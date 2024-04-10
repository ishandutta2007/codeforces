#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solve_block (const vector<int> &arr) {
  if (arr.empty()) return 0;

  vector<int> blocks (1, 0);
  for (int u : arr) {
    if (u == 0) {
      blocks.back()++;
    } else {
      blocks.push_back(0);
    }
  }

  ll ans = 0;
  for (int i = 0; i < (int) blocks.size() - 1; i++) {
    ans += (ll) (blocks[i] + 1) * (ll) (blocks[i + 1] + 1) - 1;
  }

  return ans;
}

ll solve (const vector<int> &arr) {
  ll ans = 0;
  vector<int> cur;
  for (int u : arr) {
    if (u == -1) {
      ans += solve_block(cur);
      cur.clear();
    } else {
      cur.push_back(u);
    }
  }
  ans += solve_block(cur);

  return ans;
}

const int MAX_P = 1e6 + 5;

int sieve [MAX_P];

void solve () {
  int n, e;
  cin >> n >> e;

  vector<vector<int>> arrs (e, vector<int> (0));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int rx;
    if (x == 1) {
      rx = 0;
    } else if (!sieve[x]) {
      rx = 1;
    } else {
      rx = -1;
    }

    arrs[i % e].push_back(rx);
  }

  ll ans = 0;
  for (int i = 0; i < e; i++) {
    ans += solve(arrs[i]);
  }

  cout << ans << '\n';
}

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      for (int j = 2 * i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}