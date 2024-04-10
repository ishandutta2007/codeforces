//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;



void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
    }
    ll N = n*m;
    vector<vector<ll>> d(3,vector<ll>(N,mod));
    vector<ll> dx = {1,-1,0,0};
    vector<ll> dy = {0,0,1,-1};
    for (ll c=0;c<3;c++)
    {
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++)
            {
                ll p = i*m+j;
                if (s[i][j]=='0'+1+c) d[c][p] = 0;
            }
        }
        set<pair<ll,ll>> kek;
        for (ll i=0;i<N;i++)
        {
            kek.insert({d[c][i],i});
        }
        while (kek.size()>0)
        {
            ll u = kek.begin()->Y;
            kek.erase({d[c][u],u});
            ll x = u/m;
            ll y = u%m;
            for (ll w=0;w<4;w++)
            {
                ll x2 = x+dx[w];
                ll y2 = y+dy[w];
                if (x2<0 or y2<0 or x2>=n or y2>=m) continue;
                if (s[x2][y2]=='#') continue;
                ll L = d[c][u];
                if (s[x2][y2]=='.') L++;
                ll u2 = x2*m+y2;
                if (d[c][u2]<=L) continue;
                kek.erase({d[c][u2],u2});
                d[c][u2] = L;
                kek.insert({d[c][u2],u2});
            }
        }
    }
    ll A = mod*3;
    for (ll i=0;i<N;i++)
    {
        ll x = i/m;
        ll y = i%m;
        if (s[x][y]=='#') continue;
        ll dL = 0;
        if (s[x][y]=='.') dL -= 2;
        for (ll c=0;c<3;c++) dL += d[c][i];
        A = min(A,dL);
    }
    if (A>=mod) cout << -1 << "\n";
    else cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}