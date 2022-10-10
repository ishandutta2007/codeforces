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
typedef unsigned long long int uli;
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
    vector<vi> e;
    vii edges;
    unsigned long long int ans,a,b,c;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

uli C2(lli n)
{
    if(n<=0)
        return 0;
    return n*(n+1)/2;
}

unsigned long long int solve1()
{
    unsigned long long int ans=0;
    for(auto x:edges)
    {
        const lli u=x.X,v=x.Y;
        ans+=(a*u+b*v)*(n-1-v);
        ans+=c*(C2(n-1)-C2(v));
        // dbg((a*u+b*v)*(n-1-v)+c*(C2(n-1)-C2(v)))
        ans+=(b*u+c*v)*(u);
        ans+=a*C2(u-1);
        // dbg((b*u+c*v)*(u)+a*C2(u-1))
        
        ans+=(a*u+c*v)*(v-u-1);
        ans+=b*(C2(v-1)-C2(u));
        // dbg(u,v,ans);
        // dbg("\n")
    }

    dbg("one edge",ans);
    return ans;
}

unsigned long long int solveMid(uli cst,const vi &sm,const vi &lr)
{
    unsigned long long int ans=0;
    ans+=cst*(sz(sm))*(sz(lr));
    for(auto x:sm)
        ans+=a*x*sz(lr);
    for(auto x:lr)
        ans+=c*x*sz(sm);
    return ans;
}

unsigned long long int solveCorner(uli cst,uli a,uli b,const vi &e)
{
    unsigned long long int ans=0;
    uli n=sz(e),m=0;
    ans+=cst*((n)*(n-1)/2);
    for(auto x:e)
    {
        n--;
        ans+=(x*a)*n;
        ans+=(x*b)*m;
        m++;
    }
    return ans;
}


unsigned long long int solve2()
{
    unsigned long long int ans=0;
    for(lli i=0;i<n;++i)
    {
        vi dd,ee;
        for(auto x:e[i])
        {
            if(i<x)
                ee.pb(x);
            else
                dd.pb(x);
        }

        ans+=solveMid(b*i,dd,ee);
        reverse(all(ee));
        ans+=solveCorner(a*i,c,b,ee);
        ans+=solveCorner(c*i,a,b,dd);
        // dbg(i,ans,-ans);
    }

    dbg("solve2",ans);
    return ans;
}

bool chk(const vi &a,lli x)
{
    auto it=lower_bound(all(a),x);
    return it!=a.end()&&*it==x;
}

const lli MM=200000;
const lli KK=40;
bitset<MM> edgHeavy[1+2*MM/KK];

uli solve3()
{
    uli ans=0;
    vi bb;
    vii qur;

    for(lli i=0;i<n;++i)
    {
        if(sz(e[i])>KK)
        {
            bb.pb(i);
            continue;
        }

        for(auto x:e[i])
        {
            if(x>i)
                break;
            for(auto y:e[i])
            {
                if(y<i)
                    continue;
                if(chk(e[x],y))
                    ans+=x*a+i*b+c*y;
            }
        }
    }

    const lli mm=sz(bb);
    assert(mm<2*MM/KK+1);
    for(lli i=0;i<mm;++i)
    {
        for(auto x:e[bb[i]])
            edgHeavy[i][x]=1;
    }

    for(auto x:edges)
    {
        const lli u=x.X,v=x.Y;
        auto it=lower_bound(all(bb),u+1)-bb.begin();
        while(it<mm&&bb[it]<v)
        {
            if(edgHeavy[it][u]&&edgHeavy[it][v])
                ans+=a*u+bb[it]*b+c*v;
            ++it;
        }
    }
    dbg(ans);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    cin>>a>>b>>c;
    e.resize(n);
    fo(i,m)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
        if(u>v)
            swap(u,v);
        edges.pb({u,v});
    }

    fo(i,n)
    {
        sort(all(e[i]));
        ans+=(c*i)*(i*(i-1)/2);
        ans+=(b*i)*i*(n-i-1);
        ans+=(a*i)*((n-i-2)*(n-i-1)/2);
    }

    dbg("zero",ans);
    dbg(edges);
    uli ans1=solve1();
    uli ans2=solve2();//57
    uli ans3=solve3();//38;
    dbg("b",ans1,ans2,ans3);
    // ans2-=3*ans3;
    // ans1-=2*ans2+3*ans3;
    ans+=-ans1+ans2-ans3;
    dbg(ans,-ans);
    dbg(ans1,ans2,ans3);
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}