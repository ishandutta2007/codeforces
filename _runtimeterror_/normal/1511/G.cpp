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

struct DS
{
    vector<vector<int>> bit;

    DS() {
        bit.resize(20);
        for(int i=0;i<20;++i)
            bit[i].resize((1<<(i+1)) + 1);
    }

    void insert(int x)
    {
        for(int i=0;i<20;++i)
        {
            int u = x % (1<<(i+1));
            int sz = (1<<(i+1));
            for(int j=u+1;j<=sz;j+=j&-j)
            {
                ++bit[i][j];
            }
        }
    }
    void erase(int x)
    {
        for(int i=0;i<20;++i)
        {
            int u = x % (1<<(i+1));
            int sz = (1<<(i+1));
            for(int j=u+1;j<=sz;j+=j&-j)
                --bit[i][j];
        }
    }
    int get(int i,int r)
    {
        int ans = 0;
        while(r)
        {
            ans += bit[i][r];
            r -= r & -r;
        }
        return ans;
    }
    int query(int l)
    {
        int ans = 0;
        for(int i=0;i<20;++i)
        {
            int u = l % (1<<(i+1));
            int sz = (1<<(i+1));
            int cnt = 0;
            if(u + (1<<i) < sz)
                cnt = get(i,sz) - (get(i,u + (1<<i)) - get(i,u));
            else
                cnt = get(i,u) - get(i,(u + (1<<i))%sz);
            if(cnt&1)
                ans += (1<<i);
        }
        return ans;
    }
}ok;

const int N = 200005;
vector<pii> v[N];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(m+1,0);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a[x] ^= 1;
    }
    int Q;
    cin>>Q;
    vector<int> ans(Q+1);
    for(int i=1;i<=Q;++i)
    {
        int l,r;
        cin>>l>>r;
        v[l].push_back({l,i});
        v[r+1].push_back({l,i});
    }
    for(int i=m;i>=1;--i)
    {
        if(a[i])
            ok.insert(i);
        for(auto &[l,id]:v[i])
            ans[id] ^= ok.query(l);
    }
    for(int i=1;i<=Q;++i)
    {
        cout<<"AB"[ans[i] == 0];
    }
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