//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


ll pew(ll a, ll b, ll M)
{
    ll res = 1%M;
    while (b>0)
    {
        if (b&1) res = res*a%M;
        b >>= 1;
        a = a*a%M;
    }
    return res;
}

ll phi(ll n)
{
    ll A = n;
    for (ll j=2;j*j<=n;j++)
    {
        if (n%j!=0) continue;
        A /= j;
        A *= j-1;
        while (n%j==0) n /= j;
    }
    if (n!=1)
    {
        A /= n;
        A *= n-1;
    }
    return A;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll g = __gcd(n,m);
    if (g>300000)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    vector<vector<ll>> A(g), B(g);
    {
        ll sz;
        cin >> sz;
        for (ll i=0;i<sz;i++)
        {
            ll x;
            cin >> x;
            A[x%g].push_back(x/g);
        }
        cin >> sz;
        for (ll i=0;i<sz;i++)
        {
            ll x;
            cin >> x;
            B[x%g].push_back(x/g);
        }
        for (ll i=0;i<g;i++)
        {
            sort(A[i].begin(),A[i].end());
            sort(B[i].begin(),B[i].end());
        }
    }
    if (n>m)
    {
        swap(A,B);
        swap(n,m);
    }
    n /= g;
    m /= g;
    ll pn = phi(n);
    ll pm = phi(m);
    ll n2 = pew(n,pm-1,m);
    ll m2 = pew(m,pn-1,n);
    for (ll r=0;r<g;r++)
    {
        if (A[r].size()==0 and B[r].size()==0)
        {
            cout << -1 << endl;
            return;
        }
        if (A[r].size()==n and B[r].size()==m) continue;
        ll S = -1;
        if (A[r].size()+B[r].size()>=n)
        {
            vector<ll> t(n,mod);
            for (ll x: A[r])
            {
                t[x] = x;
            }
            for (ll x: B[r])
            {
                if (t[x%n]>x)
                {
                    t[x%n] = x;
                    ans = max(ans,x*g+r+1);
                }
            }
            ll M = 0;
            for (ll i=0;i<n;i++) M = max(M,t[i]);
            if (M!=mod) S = M;
        }
        if (S==-1)
        {
            vector<pair<ll,ll>> a;
            set<ll> was;
            for (ll x: A[r])
            {
                if (was.count(x)) continue;
                was.insert(x);
                a.push_back({x*m2%n,x});
            }
            for (ll x: B[r])
            {
                if (was.count(x%n)) continue;
                was.insert(x%n);
                ans = max(ans,x*g+r+1);
                a.push_back({x*m2%n,x});
            }
            sort(a.begin(),a.end());
            ll sz = a.size();
            for (ll i=0;i<sz;i++)
            {
                ll d = a[(i+1)%sz].X-a[i].X;
                if (d<=0) d += n;
                d--;
                if (d>0) S = max(S,a[i].Y+m*d);
            }
            ans = max(ans,S*g+r+1);
        }
        S = -1;
        if (A[r].size()+B[r].size()>=m)
        {
            vector<ll> t(m,mod);
            for (ll x: B[r])
            {
                t[x] = x;
            }
            for (ll x: A[r])
            {
                if (t[x]>x)
                {
                    t[x] = x;
                    ans = max(ans,x*g+r+1);
                }
            }
            ll M = 0;
            for (ll i=0;i<m;i++) M = max(M,t[i]);
            if (M!=mod) S = M;
        }
        if (S==-1)
        {
            vector<pair<ll,ll>> a;
            set<ll> was;
            for (ll x: B[r])
            {
                if (was.count(x)) continue;
                was.insert(x);
                a.push_back({x*n2%m,x});
            }
            for (ll x: A[r])
            {
                if (was.count(x)) continue;
                was.insert(x);
                ans = max(ans,x*g+r+1);
                a.push_back({x*n2%m,x});
            }
            sort(a.begin(),a.end());
            ll sz = a.size();
            for (ll i=0;i<sz;i++)
            {
                ll d = a[(i+1)%sz].X-a[i].X;
                if (d<=0) d += m;
                d--;
                if (d>0) S = max(S,a[i].Y+n*d);
            }
            ans = max(ans,S*g+r+1);
        }
    }
    cout << ans-1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}