#include <iostream>
#include <vector>

using namespace std;

int count_cycles (const vector<int> &perm) {
  int n = perm.size(), ans = 0;
  vector<int> vis (n, 0);
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }

    ans++;
    int cur = i;
    do {
      vis[cur] = 1;
      cur = perm[cur];
    } while (cur != i);
  }

  return ans;
}

void solve () {
  int n, m;
  cin >> n >> m;

  int cyclec = n - m; // at least this many cycles
  int min_single = n;
  for (int i = 0; i <= n; i++) {
    int d = max(0, cyclec - i);
    if (i + 2 * d <= n) {
      min_single = i;
      break;
    }
  }

  vector<int> singlec (n, 0);
  vector<int> p (n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;

    int s_turn = (i - p[i] + n) % n;
    singlec[s_turn]++;
  }

  vector<int> ans;
  for (int k = 0; k < n; k++) {
    if (singlec[k] < min_single) {
      continue;
    }

    vector<int> cur = p;
    for (int i = 0; i < n; i++) {
      cur[i] += k;
      cur[i] %= n;
    }

    if (count_cycles(cur) >= cyclec) {
      ans.push_back(k);
    }
  }

  cout << (int) ans.size() << ' ';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}