#include <bits/stdc++.h>

using namespace std;

int need(int a, int b)
{
    int res = 0;
    while(a < b)
        a *= 2, res++;
    return res;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    int m[n];
    for(auto &it: m)
        cin >> it;
    sort(m, m + n, greater<int>());
    int ans = n + 1;
    for(int  msz = 0; msz <= min(22, n); msz++)
    for(int mask = 0; mask < 1 << msz; mask++)
    {
        int th = h, tw = w;
        for(int i = 0; i < msz; i++)
            if((mask >> i) & 1)
                th = min(1LL * th * m[i], 100001LL);
            else
                tw = min(1LL * tw * m[i], 100001LL);
        int ad = min(need(th, a) + need(tw, b), need(th, b) + need(tw, a));
        if(ad + msz <= n)
            ans = min(ans, msz + ad);
    }
    if(ans > n)
        ans = -1;
    cout << ans << endl;
}