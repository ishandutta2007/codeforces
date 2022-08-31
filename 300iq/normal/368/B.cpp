#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5 + 7;
int ans[MAXN];

int main() {
  set <int> s;
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--)
    s.insert(a[i]), ans[i] = s.size() + !(s.count(a[i]));
  int x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    cout << ans[--x] << endl;
  }
}