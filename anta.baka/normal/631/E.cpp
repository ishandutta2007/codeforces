#include <bits/stdc++.h>

using namespace std;

#define K first
#define L second
#define int long long

typedef long long ll;

int n, a[200001];
ll w[200001], p, ans;
vector<pair<int,ll>> l;

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    w[1] = p = a[1];
    for(int i = 2; i <= n; i++) w[i] = w[i - 1] + a[i], p += 1LL * a[i] * i;
    l.push_back({1, 0LL});
    for(int i = 2; i <= n; i++)
    {
        int X = a[i];
        int bl = 1, br = l.size() - 1;
        if(l.size() == 1 || l[0].L - l[1].L > 1LL * X * (l[1].K - l[0].K)) bl = 0;
        else while(bl < br)
        {
            int bm = (bl + br) >> 1;
            if(bl == bm) bm++;
            if(l[bm - 1].L - l[bm].L <= 1LL * X * (l[bm].K - l[bm - 1].K)) bl = bm;
            else br = bm - 1;
        }
        ans = max(ans, w[i - 1] - 1LL * i * a[i] + 1LL * l[bl].K * X + l[bl].L);

        int K = i;
        ll L = -w[i - 1];
        while(l.size() > 1)
        {
            int sz = l.size();
            if((l[sz - 2].L - l[sz - 1].L) * (K - l[sz - 1].K) < (l[sz - 1].L - L) * (l[sz - 1].K - l[sz - 2].K)) break;
            l.pop_back();
        }
        l.push_back({K, L});
    }
    //
    l.clear();
    l.push_back({-n, -w[n]});
    for(int i = n - 1; i >= 1; i--)
    {
        int X = -a[i];
        int bl = 1, br = l.size() - 1;
        if(l.size() == 1 || l[0].L - l[1].L > 1LL * X * (l[1].K - l[0].K)) bl = 0;
        else while(bl < br)
        {
            int bm = (bl + br) >> 1;
            if(bl == bm) bm++;
            if(l[bm - 1].L - l[bm].L <= 1LL * X * (l[bm].K - l[bm - 1].K)) bl = bm;
            else br = bm - 1;
        }
        ans = max(ans, w[i] - 1LL * i * a[i] + 1LL * l[bl].K * X + l[bl].L);

        int K = -i;
        ll L = -w[i];
        while(l.size() > 1)
        {
            int sz = l.size();
            if((l[sz - 2].L - l[sz - 1].L) * (K - l[sz - 1].K) < (l[sz - 1].L - L) * (l[sz - 1].K - l[sz - 2].K)) break;
            l.pop_back();
        }
        l.push_back({K, L});
    }
    cout << ans + p;
}