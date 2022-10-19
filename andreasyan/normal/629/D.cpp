#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
long long a[N];
vector<long long> v;
map<long long, int> mp;

long long t[N * 4];
void ubd(int tl, int tr, int x, long long y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        long double r, h;
        cin >> r >> h;
        a[i] = r * r * h;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int z = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = qry(1, z, 1, mp[a[i]] - 1, 1) + a[i];
        ubd(1, z, mp[a[i]], dp[i], 1);
        ans = max(ans, dp[i]);
    }

    cout << ans * acosl(-1.0) << endl;
    return 0;
}