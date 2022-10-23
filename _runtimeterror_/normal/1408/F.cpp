#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memdfs(a,0,sizeof(a))
#define mem1(a) memdfs(a,-1,sizeof(a))
#define memf(a) memdfs(a,false,sizeof(a))
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

int a[200005];
int b[200005];

int n;
vector<pll> ans;

void dfs(int l,int r)
{
    // cout<<"l r"<<l<<" "<<r<<"\n";
    if(r==l)
    {
        return ;
    }
    int mid = l + (r-l+1)/2 -1;
    dfs(l,mid);
    dfs(mid+1,r);
    for(int i=l;i<=mid;++i)
    {
        // cout<<i+mid<<"\n";
        ans.pb({a[i],a[i-l+1+mid]});
    }
}

void match(int lx,int rx,int ly,int ry)
{
    for(int i=lx;i<=rx;++i)
    {
        ans.pb({a[i],a[ly+i-lx]});
    }
}

void rot(int x)
{
    for(int i=1;i<=n;++i)
        b[i]=a[i];
    for(int i=1;i<=n;++i)
    {
        if(i>x)
            a[i] = b[i-x];
        else
            a[i] = b[i-x+n];
    }
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        a[i] = i;
    vector<ll> v;
    for(int i=0;i<=15;++i)
        if(n&(1<<i))
            v.pb(1<<i);
    int cur = 1;
    for(auto j:v)
    {
        dfs(cur,cur+j-1);
        cur += j;
    }
    cur = n;
    int i=1;
    reverse(all(v));
    while(sz(v)>2)
    {
        int l = v.back();
        v.pop_back();
        if(v.back()==l)
        {
            match(1,l,1+l,-1);
            v.pop_back();
            v.pb(l*2);
            continue;
        }
        rot(l);
        match(1,l,l+1,-1);
        v.pb(l*2);
    }
    assert(sz(ans)<=500000);
    cout<<sz(ans)<<"\n";
    for(auto j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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