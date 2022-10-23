// Har Har Mahadev
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<int> ans(m+1,-1);
    vector<int> cnt(n+1,0);
    vector<vector<int>> g(n+1),c(n+1);
    for(int i=1;i<=m;++i)
    {
        int k;
        cin>>k;
        int tmp = k;
        while(k--)
        {
            int x;
            cin>>x;
            if(tmp == 1)
                c[x].push_back(i);
            g[x].push_back(i);
        }
    }
    int val = (m+1)/2;
    int mx = -1;
    for(int i=1;i<=n;++i)
    {
        if(sz(g[i]) >= val)
        {
            mx = i;
            if(sz(c[i]) > val)
            {
                cout<<"NO\n";
                return 0;
            }
            for(auto &j:c[i])
                ans[j] = i;
            int rem = val - sz(c[i]);
            for(auto &j:g[i])
            {
                if(ans[j] != -1)
                    continue;
                if(rem == 0)
                    break;
                ans[j] = i;
                --rem;
            }
            break;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(i == mx)
            continue;
        for(auto &j:g[i])
            if(ans[j] == -1)
                ans[j] = i;
    }
    cout<<"YES\n";
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}