#include <bits/stdc++.h>

using namespace std;

vector<int> z_build(const vector<int>& s)
{
    int n(s.size());
   vector<int> z(n, 0);
   for (int l(0), r(0), i(1); i < n; ++i)
   {
       if (i <= r) z[i] = min(r - i + 1, z[i - l]);
       while (i + z[i] < n && s[i + z[i]] == s[z[i]])
           ++z[i];
       if (i + z[i] - 1 > r)
       {
           r = i + z[i] - 1;
           l = i;
       }
   }
   return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> c(n);
    for (int i(0); i < n; ++i)
        c[i] = ((a[i] - a[(i + 1) % n]) + m) % m;
    vector<int> rc(c);
    reverse(rc.begin(), rc.end());
    for (int i(0); i < n - 1; ++i) c.push_back(c[i]);
    vector<int> tmp(rc);
    tmp.reserve(3 * n + 10);
    tmp.push_back(m);
    for (int x : c) tmp.push_back(x);
    auto z = z_build(tmp);
    vector<int> ind;
    for (int i(n + 1); i < z.size(); ++i)
        if (z[i] == n)
            ind.push_back(i - (n + 1));
    vector<int> ans(ind.size());
    for (int i(0); i < ans.size(); ++i)
        ans[i] = (a[0] + a[ind[i]]) % m;
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}