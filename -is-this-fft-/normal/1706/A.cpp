#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<char> s (m, 'B');
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    cur = min(cur, m - cur - 1);
    if (s[cur] == 'A') {
      s[m - cur - 1] = 'A';
    } else {
      s[cur] = 'A';
    }
  }

  for (int i = 0; i < m; i++) {
    cout << s[i];
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