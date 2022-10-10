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
const lli maxN = 2000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi uf,pw,vis,a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli po(lli a,lli n)
{
    lli ans=1;
    while(n)
    {
        if(n&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    pw.resize(k+1);
    for(lli i=0;i<=k;++i)
        pw[i]=po(i,n);
    n=k;
    
    uf.resize(n+1,1);
    vis.resize(n+1,false);
    for(lli i=2;i<=n;++i)
    {   
        if(vis[i])
            continue;
        for(lli j=i;j<=n;j+=i)
        {
            uf[j]*=-1;
            vis[j]=true;
        }

        for(lli j=i*i;j<=n;j+=i*i)
            uf[j]*=0;
    }

    a.resize(n+1,false);
    for(lli i=1;i<=n;++i)
    if(uf[i])
    for(lli j=i;j<=n;j+=i)
    {
        a[j]+=uf[i]*(pw[j/i]-pw[(j-1)/i]);
        a[j]%=mod;
    }

    lli ans=0;
    for(lli i=1;i<=n;++i)
    {
        a[i]+=a[i-1];
        a[i]%=mod;a[i]+=mod;a[i]%=mod;
        ans+=(a[i]^i)%mod;
        ans%=mod;
    }

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}