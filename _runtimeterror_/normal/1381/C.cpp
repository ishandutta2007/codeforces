#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<ll> v(n);
    vector<ll> cnt(n+2,0);
    vector<bool> app(n+2,false);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        cnt[v[i]]++;
        app[v[i]]=true;
    }
    set<pair<int,int>> s;
    int col;
    for(int i=1;i<=n+1;++i)
        if(!app[i])
            col=i;
    for(int i=1;i<=n+1;++i)
    {
        if(cnt[i])
            s.insert({-cnt[i],i});
    }
    vector<ll> a(n+2,0);
    int val=0;
    while(val<x)
    {
        auto p=*s.begin();
        ++a[p.S];
        --cnt[p.S];
        s.erase(s.begin());
        if(cnt[p.S]>0)
            s.insert({-cnt[p.S],p.S});
        ++val;
    }
    vector<ll> ans(n,col);
    for(int i=0;i<n;++i)
    {
        if(a[v[i]])
        {
            ans[i]=v[i];
            --a[v[i]];
        }
    }
    vector<pair<int,int>> tmp;
    int mx=-1;
    for(int i=1;i<=n+1;++i)
        amax(mx,cnt[i]);
    for(int i=0;i<n;++i)
    {
        if(ans[i]==col)
            tmp.pb({v[i],i});
    }
    sort(all(tmp));
    int r=n-x;
    assert(sz(tmp)==r);
    if(mx*2<=r)
    {
        for(int i=0;i<r;++i)
        {
            ans[tmp[(i+r/2)%r].S]=tmp[i].F;
        }
        int rm=y-x;
        assert(rm>=0);
        for(int i=0;i<r-rm;++i)
            ans[tmp[i].S]=col;
    }
    else
    {
        int u=2*(r-mx);
        if(u<y-x)
        {
            cout<<"NO\n";return 0;
        }
        vector<int> match;
        vector<pair<int,int>> left,right;
        for(int i=0;i<r;++i)
        {
            if(cnt[tmp[i].F]==mx)
                right.pb(tmp[i]);
            else
                left.pb(tmp[i]);
        }
        //assert(sz(left)==r-mx);
        for(int i=0;i<r-mx;++i)
        {
            ans[left[i].S]=right[i].F,ans[right[i].S]=left[i].F;
            match.pb(right[i].S);match.pb(left[i].S);
        }
        for(int i=y-x;i<sz(match);++i)
            ans[match[i]]=col;
    }
    cout<<"YES\n";
    for(int i=0;i<n;++i)
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