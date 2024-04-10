#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 20;
double sum[2][maxn];

void build(int l, int r)
{
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    int h = (r - l) / 2;
    build(l, m);
    build(m, r);
    for(int i = m; i < r; i++)
    {
        sum[0][i] += sum[0][i - h];
        sum[1][i] += sum[1][i - h];
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    double p[n];
    for(auto &it: p)
        cin >> it;
    if(count_if(p, p + n, [&](double x){return x > 0;}) <= k)
    {
        for(auto it: p)
            cout << (it > 0 ? 1 : 0) << ' ';
        return 0;
    }
    int sz = 1 << n;
    for(int msk = 0; msk < sz; msk++)
        if(__builtin_popcount(msk) <= k)
        {
            double & sm = sum[__builtin_parity(msk)][msk];
            for(int i = 0; i < n; i++)
                if((msk >> i) & 1)
                    sm += p[i];
            sm /= 1 - sm;
        }
    build(0, sz);
    double ans[n];
    fill(ans, ans + n, 0);
    for(int msk = 0; msk < sz; msk++)
        if(__builtin_popcount(msk) == k)
        {
            double sm = 0;
            for(int i = 0; i < n; i++)
                if((msk >> i) & 1)
                    sm += p[i];
            sm = (1 - sm) * (sum[__builtin_parity(msk)][msk] - sum[1 ^ __builtin_parity(msk)][msk]);
            for(int i = 0; i < n; i++)
                if((msk >> i) & 1)
                    ans[i] += sm;
        }
    for(auto it: ans)
        cout << it << ' ';
	return 0;
}