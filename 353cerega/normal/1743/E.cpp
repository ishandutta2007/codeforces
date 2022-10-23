//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;



void solve()
{
    ll a1, t1, a2, t2;
    cin >> a1 >> t1 >> a2 >> t2;
    ll H, S;
    cin >> H >> S;
    ll mx = H;
    vector<ll> nxt(mx+1,mod*mod);
    for (ll k=1;k<=mx;k++)
    {
        ll T = t1*k;
        ll k2 = T/t2;
        ll D = k*(a1-S)+a2+(k2-1)*(a2-S);
        if (k2==0) D = k*(a1-S);
        D = min(D,mx);
        nxt[D] = min(nxt[D],T);
        D = k*(a1-S)+k2*(a2-S);
        D = min(D,mx);
        nxt[D] = min(nxt[D],T);
    }
    swap(a1,a2);
    swap(t1,t2);
    for (ll k=1;k<=mx;k++)
    {
        ll T = t1*k;
        ll k2 = T/t2;
        ll D = k*(a1-S)+a2+(k2-1)*(a2-S);
        if (k2==0) D = k*(a1-S);
        D = min(D,mx);
        nxt[D] = min(nxt[D],T);
        D = k*(a1-S)+k2*(a2-S);
        D = min(D,mx);
        nxt[D] = min(nxt[D],T);
    }
    vector<ll> dp(H+1,mod*mod);
    dp[0] = 0;
    for (ll j=1;j<=H;j++)
    {
        for (ll w=1;w<=mx;w++)
        {
            dp[j] = min(dp[j],dp[max(j-w,0LL)]+nxt[w]);
        }
    }
    cout << dp[H] << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}