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

const int N = 5e6+5;

int l[N],r[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    map<int,vector<int>> mp;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        mp[a[i]].pb(i);
    }
    vector<int> u;
    for(auto &j:mp)
    {
        if(sz(j.S) >= 4)
        {
            cout<<"YES\n";
            for(int i=0;i<4;++i)
                cout<<j.S[i]<<" ";
            return 0;
        }
        if(sz(j.S) >= 2)
            u.pb(j.F);
    }
    if(sz(u) >= 2)
    {
        cout<<"YES\n";
        cout<<mp[u[0]][0]<<" "<<mp[u[1]][0]<<" "<<mp[u[0]][1]<<" "<<mp[u[1]][1]<<"\n";
        return 0;
    }
    if(sz(u) == 1)
    {
        int sum = 2*u[0];
        for(int i=1;i<=n;++i)
        {
            if(a[i] == u[0])
                continue;
            if(mp.count(sum-a[i]))
            {
                cout<<"YES\n";
                cout<<mp[u[0]][0]<<" "<<mp[u[0]][1]<<" "<<i<<" "<<mp[sum-a[i]][0]<<"\n";
                return 0;
            }
        }
    }
    vector<int> ans;
    for(auto &j:mp)
    {
        if(sz(ans) < 3000)
            ans.pb(j.F);
    }
    n = sz(ans);
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int sum = ans[i] + ans[j];
            if(l[sum] != 0)
            {
                cout<<"YES\n";
                cout<<l[sum]<<" "<<r[sum]<<" "<<mp[ans[i]][0]<<" "<<mp[ans[j]][0]<<"\n";
                return 0;
            }
            l[sum] = mp[ans[i]][0],r[sum] = mp[ans[j]][0];
        }
    }
    cout<<"NO\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}