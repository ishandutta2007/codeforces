#include <bits/stdc++.h>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> p(n);
  vector <int> f(m);
  vector <int> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    s[i] = x;
    f[x] = max(f[x], p[i]);
  }
  int ans = 0;
  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    x--;
    if (f[s[x]] != p[x]) ans++;
  }
  cout << ans << endl;
}