#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define K first
#define L second

int n, a[200001];
ll p[200001], s[200001], ans;
vector<pair<int,ll>> l;

inline long double x(pair<int,ll> &a, pair<int,ll> &b)
{
    return (long double)(a.L - b.L) / (b.K - a.K);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    p[1] = s[1] = a[1];
    for(int i = 2; i <= n; i++) p[i] = p[i - 1] + a[i], s[i] = s[i - 1] + 1LL * a[i] * i;
    ans = max(ans, s[1]);
    l.push_back({1, 0});
    for(int i = 2; i <= n; i++)
    {
        ans = max(ans, s[i]);
        ll X = -p[i];
        int bl = 1, br = l.size() - 1;
        if(l.size() == 1 || X < x(l[0], l[1])) bl = 0;
        else while(bl < br)
        {
            int bm = (bl + br) >> 1;
            if(bl == bm) bm++;
            if(x(l[bm - 1], l[bm]) <= X) bl = bm;
            else br = bm - 1;
        }
        ans = max(ans, s[i] + l[bl].K * X + l[bl].L);

        pair<int,ll> me = {i, i * p[i] - s[i]};
        while(l.size() > 1)
        {
            int sz = l.size();
            if(x(l[sz - 2], l[sz - 1]) < x(l[sz - 1], me)) break;
            l.pop_back();
        }
        l.push_back(me);
    }
    cout << ans;
}