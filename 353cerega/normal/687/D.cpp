//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

const ll MX = 3e6;
vector<pair<ll,pair<ll,ll>>> e;
vector<vector<pair<ll,pair<ll,ll>>>> e2(MX);
vector<vector<ll>> gr;
vector<ll> col, num;

void build(ll v, ll tl, ll tr)
{
    {
        vector<pair<ll,pair<ll,ll>>> cur;
        for (ll i=tl;i<=tr;i++) cur.push_back(e[i]);
        sort(cur.begin(),cur.end());
        reverse(cur.begin(),cur.end());
        vector<ll> was;
        for (ll i=0;i<cur.size();i++)
        {
            ll U = cur[i].Y.X;
            ll V = cur[i].Y.Y;
            ll D = col[U]^col[V]^1;
            U = num[U];
            V = num[V];
            if (U==V and D==0) continue;
            e2[v].push_back(cur[i]);
            if (U==V and D==1) break;
            was.push_back(U);
            was.push_back(V);
            if (gr[U].size()<gr[V].size()) swap(U,V);
            for (ll x: gr[V])
            {
                num[x] = U;
                gr[U].push_back(x);
                col[x] ^= D;
            }
            gr[V].clear();
        }
        for (ll x: was)
        {
            num[x] = x;
            col[x] = 0;
            gr[x].clear();
            gr[x].push_back(x);
        }
    }
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
}

vector<ll> Q;

void get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r)
    {
        Q.push_back(v);
        return;
    }
    ll tm = (tl+tr)/2;
    if (tm>=l) get(v*2,tl,tm,l,r);
    if (tm<r) get(v*2+1,tm+1,tr,l,r);
}

void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    e.resize(m);
    for (ll i=0;i<m;i++)
    {
        cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
        e[i].Y.X--, e[i].Y.Y--;
    }
    col.resize(n);
    gr.resize(n);
    num.resize(n);
    for (ll i=0;i<n;i++)
    {
        gr[i].push_back(i);
        num[i] = i;
    }
    build(1,0,m-1);
    for (ll w=0;w<q;w++)
    {
        ll L, R;
        cin >> L >> R;
        Q.clear();
        L--, R--;
        get(1,0,m-1,L,R);
        L = -1, R = mod;
        while (R-L>1)
        {
            ll M = (L+R)/2;
            for (ll i=0;i<n;i++)
            {
                gr[i].clear();
                gr[i].push_back(i);
                num[i] = i;
                col[i] = 0;
            }
            ll F = 0;
            for (ll v: Q)
            {
                for (ll i=0;i<e2[v].size() and e2[v][i].X>=M;i++)
                {
                    ll U = e2[v][i].Y.X;
                    ll V = e2[v][i].Y.Y;
                    ll D = col[U]^col[V]^1;
                    U = num[U];
                    V = num[V];
                    if (U==V and D==0) continue;
                    if (U==V and D==1)
                    {
                        F = 1;
                        break;
                    }
                    if (gr[U].size()<gr[V].size()) swap(U,V);
                    for (ll x: gr[V])
                    {
                        num[x] = U;
                        gr[U].push_back(x);
                        col[x] ^= D;
                    }
                    gr[V].clear();
                }
                if (F==1) break;
            }
            if (F==1) L = M;
            else R = M;
        }
        cout << L << "\n";
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