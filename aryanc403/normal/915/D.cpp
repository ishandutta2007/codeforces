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
#define sz(x) ((lli)(x).size())
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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
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
    lli m,of;
    string s;
    vi col,a;
    vector<vii> e;
    bool fl;
    bool gl;
    vii par;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

//col unvis,stack,vis.

void dfs(lli u,ii p)
{
    if(fl)
        return;
    if(col[u]==2)
        return;
    if(col[u]==1)
    {
        fl=true;
        dbg(gl);
        if(!gl)
            return;
        dbg(par);
        dbg(u,p);
        gl=false;
        lli v=p.X;
        a.pb(p.Y);
        while(v!=u)
        {
            a.pb(par[v].Y);
            v=par[v].X;
        }
    
        return;
    }

    par[u]=p;
    col[u]=1;
    for(auto x:e[u])
    {
        if(x.Y==of)
            continue;
        dfs(x.X,{u,x.Y});
    }
    col[u]=2;
}

bool chk()
{
    fl=false;
    col.clear();
    col.resize(n+1,0);

    for(lli i=1;i<=n;++i)
        dfs(i,{-1,-1});

    return fl;
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
    repA(i,1,m)
    {
        cin>>u>>v;
        e[u].pb({v,i});
    }

    gl=true;
    par.resize(n+1,{-1,-1});
    dbg(a);
    if(!chk()&&a.empty())
    {
        cout<<"YES"<<endl;
        return 0;
    }

    gl=false;
    for(auto x:a)
    {
        of=x;
        if(!chk())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}   aryanc403();
    return 0;
}