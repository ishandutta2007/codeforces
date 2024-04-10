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
    lli m;
    string s;
    vector<pair<string,ii>> a;
    vi ans,val;

lli dfs1(lli u)
{
    if(a[u].X=="IN")
        return val[u]=a[u].Y.X;

    if(a[u].X=="NOT")
        return val[u]=!dfs1(a[u].Y.X);
    
    if(a[u].X=="AND")
        return val[u]=dfs1(a[u].Y.X)&dfs1(a[u].Y.Y);
    
    if(a[u].X=="OR")
        return val[u]=dfs1(a[u].Y.X)|dfs1(a[u].Y.Y);
    
    if(a[u].X=="XOR")
        return val[u]=dfs1(a[u].Y.X)^dfs1(a[u].Y.Y);
    
    assert(false);
}

void dfs2(lli u)
{
    dbg(u);
    if(a[u].X=="IN")
    {
        dbg(u,"CG");
        ans[u]=!ans[u];
        return;
    }

    if(a[u].X=="NOT")
    {
        dfs2(a[u].Y.X);
        return;
    }

    if(a[u].X=="AND")
    {
        const lli l=a[u].Y.X,r=a[u].Y.Y;
        dbg(a[u],val[u],val[l],val[r]);
        if(val[u]==0)
        {
            if(!val[l]&&!val[r])
                return;
            if(!val[l])
                dfs2(l);
            if(!val[r])
                dfs2(r);
            return;
        }
        dfs2(l);
        dfs2(r);
        return;
    }

    if(a[u].X=="XOR")
    {
        const lli l=a[u].Y.X,r=a[u].Y.Y;
        dfs2(l);
        dfs2(r);
    }

    if(a[u].X=="OR")
    {
        const lli l=a[u].Y.X,r=a[u].Y.Y;
        if(val[u])
        {
            if(val[l]&&val[r])
                return;
            if(val[l])
                dfs2(l);
            if(val[r])
                dfs2(r);
            return;
        }
        dfs2(l);
        dfs2(r);
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);
    a.resize(1);

    repA(i,1,n)
    {
        cin>>s;
        if(s=="IN"||s=="NOT")
        {
            cin>>l;
            a.pb({s,{l,l}});
        }
        else
        {
            cin>>l>>r;
            a.pb({s,{l,r}});
        }
    }

    val.resize(n+1,0);
    ans.resize(n+1,dfs1(1));
    dbg(val);
    dfs2(1);

    repA(i,1,n)
        if(a[i].X=="IN")
            cout<<ans[i];

}   aryanc403();
    return 0;
}