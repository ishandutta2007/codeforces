#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first

const int MAXN = 200009;
int a[MAXN];
int n;

int f(int l, int r)
{
    if (r - l <= 1)
        return 0;
    int m = (l + r) / 2;
    int ans = f(l, m) + f(m, r);
    int ma = 0;
    map<int, int> mp1;
    map<int, int> mp2;
    for (int i = m - 1; i >= l; i--)
    {
        ma = max(a[i], ma);
        mp1.emplace(a[i], ma);
    }
    ma = 0;
    for (int i = m; i < r; i++)
    {
        ma = max(a[i], ma);
        mp2.emplace(a[i], ma);
    }
    for (auto e : mp1)
    {
        auto j = mp2.find(e.ss - e.ff);
        if (j == mp2.end())
            continue;
        if ((*j).ss <= e.ss)
            ans++;
    }
    for (auto e : mp2)
    {
        auto j = mp1.find(e.ss - e.ff);
        if (j == mp1.end())
            continue;
        if ((*j).ss <= e.ss)
            ans++;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << f(0, n);
}