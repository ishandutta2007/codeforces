#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, k, n, s;
  cin >> m >> k >> n >> s;
  vector <int> a(m);
  for (int &x : a)
  {
    cin >> x;
    x--;
  }
  map <int, int> need;
  for (int i = 0; i < s; i++)
  {
    int x;
    cin >> x;
    x--;
    need[x]++;
  }
  int good = 0;
  map <int, int> me;
  auto add = [&] (int x)
  {
    me[x]++;
    if (me[x] == need[x]) good++;
  };
  auto del = [&] (int x)
  {
    if (me[x] == need[x]) good--;
    me[x]--;
  };
  s = need.size();
  int r = 0;
  for (int l = 0; l < m; l++)
  {
    while (r < m && good < s)
    {
      add(a[r]);
      r++;
    }
    int musor = l % k + max(0, r - l - k);
    if (m - musor >= n * k && good == s)
    {
     vector <int> bad;
      for (int i = 0; i < l % k; i++)
      {
        bad.push_back(i);
      }
      me.clear();
      vector <int> trash;
      for (int i = l; i < r; i++)
      {
        if (me[a[i]] + 1 <= need[a[i]])
        {
          me[a[i]]++;
        }
        else
        {
          trash.push_back(i);
        }
      }
      while (trash.size() > max(0, r - l - k))
      {
        trash.pop_back();
      }
      for (int x : trash) bad.push_back(x);
      cout << bad.size() << endl;
      for (int x : bad) cout << x + 1 << ' ';
      cout << endl;
      return 0;
    }
    del(a[l]);
  }
  cout << -1 << '\n';
  return 0;
}