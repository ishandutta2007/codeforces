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
int hh[100005],mm[100005];

struct dynode{
    ll val;
    int l,r;
    int id;
    dynode(): l(-1), r(-1){}
};
const int Q=100001;
const int LOGN=30;
const int NN=Q*4*LOGN;
struct dySeg {

    dynode tree[NN];
    ll lazy[NN];
    int cursz=0;
    int root;

    dySeg () {
        root = cursz++;
        tree[root].val=0;
        tree[root].id=0;
    }
    inline void extend (int u, int l, int r)
    {
        int mid=(l+r)/2;
        if(tree[u].l!=-1)
            return ;
        int v = cursz++;
        tree[u].l=v;
        tree[v].val=0;
        tree[v].id=l;

        v=cursz++;
        tree[u].r=v;
        tree[v].val=0;
        tree[v].id=mid+1;
    }

    void update(int v,int st,int en,int idx,ll val)
    {
        if(st==en)
        {
            tree[v].val=val;
            return ;
        }
        int mid=(st+en)/2;

        extend(v,st,en);
        if(idx<=mid)
            update(tree[v].l,st,mid,idx,val);
        else
            update(tree[v].r,mid+1,en,idx,val);
        tree[v].val=tree[tree[v].l].val+tree[tree[v].r].val;
    }
    inline void pushdown(int v,int l,int r)
    {
        tree[v].val+=lazy[v];
        if(l!=r)
        {
            extend(v,l,r);
            lazy[tree[v].l]+=lazy[v];
            lazy[tree[v].r]+=lazy[v];
        }
        lazy[v]=0;
    }
    void rupdate(int v,int st,int en,int l,int r,ll val)
    {
        if(lazy[v]!=0)
            pushdown(v,st,en);
        if(st>r || en<l)
            return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        extend(v,st,en);

        int mid=(st+en)/2;
        rupdate(tree[v].l,st,mid,l,r,val);
        rupdate(tree[v].r,mid+1,en,l,r,val);
        tree[v].val=min(tree[tree[v].l].val,tree[tree[v].r].val);
        if(tree[v].val==tree[tree[v].l].val)
            tree[v].id=tree[tree[v].l].id;
        else
            tree[v].id=tree[tree[v].r].id;
    }

    pll query(int v,int st,int en,int l,int r)
    {
        if(lazy[v]!=0)
            pushdown(v,st,en);
        if(st>r || en<l)
            return {2e9,-1};
        if(st>=l && en<=r)
            return {tree[v].val,tree[v].id};

        int mid=(st+en)/2;
        extend(v,st,en);
        return min(query(tree[v].l,st,mid,l,r),query(tree[v].r,mid+1,en,l,r));

    }

}seg;

int _runtimeTerror_()
{
    int n,h,m,k;
    cin>>n>>h>>m>>k;
    for(int i=0;i<n;++i)
        cin>>hh[i]>>mm[i];

    for(int i=0;i<n;++i)
    {
        int l,r;
        int x=mm[i];
        if(mm[i]>=m/2)
        {
            x=mm[i]-m/2;
        }
        if(x+k-1<m/2)
            seg.rupdate(seg.root,0,m-1,x+1,x+k-1,1);
        else
            seg.rupdate(seg.root,0,m-1,x+1,m/2-1,1);
        if(x+k-1>=m/2)
            seg.rupdate(seg.root,0,m-1,0,(x+k-1)%(m/2),1);
    }
    auto ans=seg.query(seg.root,0,m-1,0,m/2-1);
    cout<<ans.F<<" "<<ans.S<<'\n';
    //int x=ans.S,l,r;
    for(int i=0;i<n;++i)
    {
        int x=mm[i];
        if(mm[i]>=m/2)
        {
            x=mm[i]-m/2;
        }
        if(x+k-1<m/2)
        {
            if(ans.S>=x+1 && ans.S<=x+k-1)
            {
                cout<<i+1<<" ";continue;
            }
        }
            
        else
        {
            if(ans.S>=x+1 && ans.S<=m/2-1)
            {
                cout<<i+1<<" ";continue;
            }
        }
        if(x+k-1>=m/2)
        {
            int val=(x+k-1)%(m/2);
            if(ans.S>=0 and ans.S<=val)
            {
                cout<<i+1<<" ";continue;
            }
            
        }
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