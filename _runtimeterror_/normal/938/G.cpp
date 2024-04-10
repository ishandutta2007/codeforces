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

const int N = 200005;

struct dsu_node
{
    int x, rnkx, y, rnky;
    int sz;
    vector<int> Xor;
    dsu_node(){}
    dsu_node(int x_,int rnkx_,int y_,int rnky_,int sz_): x(x_),y(y_),rnkx(rnkx_),rnky(rnky_){sz = sz_;}
};
struct dsu_with_rollback
{
    vector<int> r,p;
    vector<vector<int>> elements;
    vector<int> XorToRoot;
    int comps;
    stack<dsu_node> st;
 
    dsu_with_rollback(){}
 
    dsu_with_rollback(int n) : comps(n)
    {
        r.resize(n+2);p.resize(n+2);
        XorToRoot.resize(n+1);
        elements.resize(n+1);
        for(int i=0;i<=n;++i)
            p[i]=i,r[i]=0,XorToRoot[i] = 0,elements[i].pb(i);
    }
    inline int parent(int i)
    {
       return (i==p[i])?i:parent(p[i]);
    }
    void merge(int x,int y,int w)
    {
        int lx = x,ly = y;
        x=parent(x),y=parent(y);
        int yy = sz(elements[x]) + sz(elements[y]);
        if(sz(elements[x])>sz(elements[y]))
            swap(x,y),swap(lx,ly);
        st.push(dsu_node(x,r[x],y,r[y],sz(elements[y])));
        p[x] = y;
        bool f = true;
        for(int &j:elements[x])
        {
            st.top().Xor.pb(XorToRoot[j]);
            if(j==lx)
            {
                f = false;
                elements[y].pb(lx);
                continue;
            }
            int val = XorToRoot[j]^XorToRoot[lx]^w^XorToRoot[ly];
            XorToRoot[j] = val;
            elements[y].pb(j);
        }
        XorToRoot[lx] = w^XorToRoot[ly];
        elements[x].clear();
    }
    void rollback()
    {
        if(st.empty())return ;
        dsu_node val= st.top();st.pop();
        ++comps;
        p[val.x]=val.x,p[val.y]=val.y;
        while(sz(elements[val.y])>val.sz)
        {
            elements[val.x].pb(elements[val.y].back());
            elements[val.y].pop_back();
        }
        reverse(all(elements[val.x]));
        for(int i=0;i<sz(elements[val.x]);++i)
            XorToRoot[elements[val.x][i]] = val.Xor[i];
    }
};
 
struct query{
    int x,y,w;
    query(int x_,int y_,ll w_):x(x_),y(y_),w(w_){}
};
struct Tree{
    struct basis
    {
        int mask[31];
        basis()
        {
            for(int i=0;i<=30;++i)
                mask[i] = 0;
        }
        void add(int x)
        {
            for(int j=29;j>=0;--j)
            {
                if((x&(1<<j))==0)
                    continue;
                if(!mask[j])
                    mask[j] = x;
                x ^= mask[j];
            }
        }
        int query(int x)
        {
            for(int j=29;j>=0;--j)
            {
                if((x&(1<<j))==0)
                    continue;
                x ^= mask[j];
            }
            return x;
        }
    };
    vector<vector<query>> tree;
    vector<pair<int,int>> Q;
    vector<basis> tr;
    dsu_with_rollback dsu;
    int n,T;  
    vector<ll> ans;
 
    Tree(int n_,int T_): n(n_),T(T_){
        dsu = dsu_with_rollback(n);
        tree.resize(4*T + 10);
        tr.resize(4*T + 1);
        ans.resize(T+4);
    }
 
    void rupdate(int v,int st,int en,int l,int r,query &q)
    {
        if(st>r || en<l)return ;
        if(st>=l && en<=r)
        {
            tree[v].pb(q);
            return ;
        }
        int mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,q);
        rupdate(v<<1 | 1,mid+1,en,l,r,q);
    }
    inline void add_edge(int l,int r,int x,int y,ll w)
    {
        query q(x,y,w);
        rupdate(1,0,T-1,l,r,q);
    }
    void dfs(int v,int st,int en)
    {
        if(en<st)
            return ;
        int cnt = 0;
        for(auto &k:tree[v])
        {
            int x = dsu.parent(k.x),y = dsu.parent(k.y);
            if(x==y)
            {
                tr[v].add(dsu.XorToRoot[k.x]^dsu.XorToRoot[k.y]^k.w);
            }
            else
            {
                ++cnt;
                dsu.merge(k.x,k.y,k.w);
            }
        }
        if(st==en)
        {
            if(Q[st].F!=-1)
            {
                ans[st]=tr[v].query(dsu.XorToRoot[Q[st].F]^dsu.XorToRoot[Q[st].S]);
            }
        }
        else
        {
            int mid=(st+en)>>1;
            tr[v<<1] = tr[v];
            tr[v<<1 | 1] = tr[v];
            dfs(v<<1,st,mid);
            dfs(v<<1 | 1,mid+1,en);
        }
        while(cnt--)
            dsu.rollback();
    }
    void solve()
    {
        dfs(1,0,T-1);
    }
};
int n,m;
map<pair<int,int>,pair<int,int>> l;

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,d;
        cin>>x>>y>>d;
        l[{x,y}] = l[{y,x}] = {0,d};
    }
    int Q;
    cin>>Q;
    Tree dsu(n,Q);
    for(int i=0;i<Q;++i)
    {
        int tt,x,y,d;
        cin>>tt>>x>>y;
        if(tt==1)
        {
            cin>>d;
            l[{x,y}]= l[{y,x}] = {i,d};
            dsu.Q.pb({-1,-1});
        }
        else if(tt==2)
        {
            dsu.add_edge(l[{x,y}].F,i-1,x,y,l[{x,y}].S);
            l.erase({x,y});
            l.erase({y,x});
            dsu.Q.pb({-1,-1});
        }
        else if(tt==3)
        {
            dsu.Q.pb({x,y});
        }
    }
    for(auto &j:l)
    {
        if(j.F.F<j.F.S)
            dsu.add_edge(j.S.F,Q-1,j.F.F,j.F.S,j.S.S);
    }
    l.clear();    
    dsu.solve();
    for(int i=0;i<Q;++i)
    {
        if(dsu.Q[i].F!=-1)
            cout<<dsu.ans[i]<<"\n";
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