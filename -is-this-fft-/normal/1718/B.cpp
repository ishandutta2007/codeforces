#include <iostream>
#include <vector>

using namespace std;

const int MAX_F = 44;

int fib [MAX_F];

vector<int> reduce (int x) {
  vector<int> cur;
  for (int i = MAX_F - 1; i >= 0; i--) {
    if (fib[i] <= x) {
      cur.push_back(i);
      x -= fib[i];
      i--;
    }
  }

  if (x != 0) {
    return vector<int> (0);
  }
  return cur;
}

bool is_ok (const vector<int> &cnt) {
  int mx = 1;
  for (int u : cnt) {
    if (u > mx) return false;
    mx = u;
  }
  return true;
}

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> red (n);
  for (int i = 0; i < n; i++) {
    red[i] = reduce(arr[i]);
    if (red[i].empty()) {
      cout << "NO" << '\n';
      return;
    }
  }

  for (int k = 0; k <= n; k++) {
    vector<int> cnt (MAX_F, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int) red[i].size(); j++) {
        if (i == k && j == (int) red[i].size() - 1 && red[i][j] % 2 == 1) {
          for (int l = red[i][j] - 1; l >= 0; l -= 2) {
            cnt[l]++;
          }
        } else {
          cnt[red[i][j]]++;
        }
      }
    }

    if (is_ok(cnt)) {
      cout << "YES" << '\n';
      return;
    }
  }

  cout << "nO" << '\n';
}

int main () {
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < MAX_F; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    cerr << fib[i] << '\n';
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}