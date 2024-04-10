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
    lli ans;
    string s;
    vii a;
    vector<vi> dpf,dpb;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli calc(lli x,lli y,lli z)
{
    if(x<0||y<0||z<0)
        return LLONG_MAX;
    if(x>1e9||y>1e9||z>1e9)
        return LLONG_MAX;
    dbg(x,y,z,(x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z))
    return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}

void solve()
{
    n=sz(a);
    dpf.clear();dpf.resize(n,vi(3,-1e9-5));
    dpb.clear();dpb.resize(n,vi(3,1e9+5));
    ans=LLONG_MAX;
    dbg(ans/1e18);
    repA(i,1,n-1)
    {
        dpf[i]=dpf[i-1];
        dpf[i][a[i-1].Y]=a[i-1].X;
    }

    repD(i,n-2,0)
    {
        dpb[i]=dpb[i+1];
        dpb[i][a[i+1].Y]=a[i+1].X;
    }

    fo(i,n)
    {
        lli j,k;
        if(a[i].Y==0)
        {
            j=1;
            k=2;
        }

        if(a[i].Y==1)
        {
            j=0;
            k=2;
        }

        if(a[i].Y==2)
        {
            j=1;
            k=0;
        }

        ans=min(ans,calc(dpf[i][j],a[i].X,dpb[i][k]));
        swap(j,k);
        ans=min(ans,calc(dpf[i][j],a[i].X,dpb[i][k]));
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n>>m>>k;
    a.clear();a.reserve(n+m+k);
    fo(i,n)
    {
        cin>>in;
        a.pb({in,0});
    }

    fo(i,m)
    {
        cin>>in;
        a.pb({in,1});
    }

    fo(i,k)
    {
        cin>>in;
        a.pb({in,2});
    }

    sort(all(a));
    ans=INF;
    n=sz(a);
    solve();
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}