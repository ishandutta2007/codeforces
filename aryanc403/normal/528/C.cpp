/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (lli)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<lli> dg;
    vector<vii> e;
    vii ans;
    vi b;
    vector<bool> vis,visv;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli dfs(lli u,lli p,lli pp)
{
    if(visv[u])
    {
        if(vis[p])
            return 0;
        ans.pb({u,pp});
        dbg(p,"add",u,pp);
        vis[p]=true;
        return 1;
    }
    lli f=dg[u];
    dbg(u,e[u]);
    visv[u]=true;
    for(auto x:e[u])
    {
        if(x.Y==p)
            continue;
        f^=dfs(x.X,x.Y,u);
    }
    dbg(u,f);
    assert(!vis[p]);
    vis[p]=true;
    if(f)
    {
        if(pp)
        {
            ans.pb({pp,u});
            dbg(p,"add",pp,u);
        }
        return 0;
    }

    if(pp)
    {
        ans.pb({u,pp});
        dbg(p,"add",u,pp);
    }
    return 1;
}

void hotfix()
{
    dbg(ans);
    dg.clear();
    dg.resize(n+1,0);
    for(auto x:ans)
        dg[x.X]^=1;
    repA(i,1,n)
    {
        if(!dg[i])
            continue;
        ans.pb({i,i});
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    e.resize(n+1);
    dg.resize(n+1);
    lli cnt=m;

    repA(i,1,m)
    {
        cin>>u>>v;
        dbg(u,v);
        if(u==v)
        {
            ans.pb({u,v});
            dg[u]^=1;
            i--;m--;
            continue;
        }

        e[u].pb({v,i});
        e[v].pb({u,i});
    }

    repA(i,1,n)
    {
        if(sz(e[i])%2)
            b.pb(i);
    }

    dbg(dg);
    dbg(b);
    assert(sz(b)%2==0);
    for(lli i=0;i<sz(b);i+=2)
    {
        cnt++;
        u=b[i];v=b[i+1];
        e[u].pb({v,++m});
        e[v].pb({u,m});
    }

    if(cnt%2)
    {
        ans.pb({1,1});
        dg[1]^=1;
    }

    dbg(e);

    vis.resize(m+1,false);
    visv.resize(n+1,false);
    // dfs(1,0,0);
    assert(dfs(1,0,0)==1);
    // hotfix();
    dbg(vis);
    
    cout<<sz(ans)<<endl;
    for(auto x:ans)
        cout<<x.X<<" "<<x.Y<<endl;
    
}   aryanc403();
    return 0;
}