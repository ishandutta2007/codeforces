#include <bits/stdc++.h>

using namespace std;

struct triple
{
  int first, second;
  bool flag;
};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  map <int, int> cnt;
  cnt[0] = k;
  int ptr = 0;
  int have = 0;
  vector <triple> ret;
  int opa = 0;
  int ans = 0;
  for (int t = 0; ; t++)
  {
    if (ptr == n && ret.empty()) break;
    have += cnt[t];
    while (ptr < n && have > 0)
    {
      ret.push_back({0, a[ptr], 0});
      have--;
      cnt[t + a[ptr]]++;
      ptr++;
    }
    vector <triple> go;

    int score = int(100.0 * opa / n + 0.5);
    for (auto &c : ret)
    {
      c.first++;
      if (c.first == score && !c.flag)
      {
        ans++;
        c.flag = true;
      }
      if (c.first != c.second)
        go.push_back(c);
      else
        opa++;
    }
    ret = go;
  }
  cout << ans << endl;
}