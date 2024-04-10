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
    for (ll i=0;i<n;i++) cin >> s[i];
    vector<ll> dx = {1,-1,0,0};
    vector<ll> dy = {0,0,1,-1};
    vector<vector<ll>> D(n,vector<ll>(m));
    vector<pair<ll,ll>> q;
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]=='*') continue;
            for (ll d=0;d<4;d++)
            {
                ll x2 = i+dx[d];
                ll y2 = j+dy[d];
                if (x2<0 or y2<0 or x2>=n or y2>=m) continue;
                if (s[x2][y2]=='*') continue;
                D[i][j]++;
            }
            if (D[i][j]==0)
            {
                cout << "Not unique\n";
                return;
            }
            if (D[i][j]==1) q.push_back({i,j});
        }
    }
    for (ll w=0;w<q.size();w++)
    {
        ll i = q[w].X;
        ll j = q[w].Y;
        if (s[i][j]!='.') continue;
        ll d = 0;
        ll x2, y2;
        for (;d<4;d++)
        {
            x2 = i+dx[d];
            y2 = j+dy[d];
            if (x2<0 or y2<0 or x2>=n or y2>=m) continue;
            if (s[x2][y2]!='.') continue;
            break;
        }
        if (d==4)
        {
            cout << "Not unique\n";
            return;
        }
        for (ll d2=0;d2<4;d2++)
        {
            ll x3 = x2+dx[d2];
            ll y3 = y2+dy[d2];
            if (x3<0 or y3<0 or x3>=n or y3>=m) continue;
            if (s[x3][y3]!='.') continue;
            D[x3][y3]--;
            if (D[x3][y3]==1) q.push_back({x3,y3});
        }
        if (d&1)
        {
            swap(i,x2);
            swap(j,y2);
            d--;
        }
        if (d==0) s[i][j] = '^', s[x2][y2] = 'v';
        else s[i][j] = '<', s[x2][y2] = '>';
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]=='.')
            {
                cout << "Not unique\n";
                return;
            }
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            cout << s[i][j];
        }
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}