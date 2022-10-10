/* in the name of Anton */

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
    set<ii> a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

vii dir;

ii addOne(set<ii> &a,map<ii,lli> &mm)
{
    map<ii,lli> nmm;
    for(auto z:mm)
    {
        auto x=z.X;
        for(auto y:dir)
        if(a.find({x.X+y.X,x.Y+y.Y})==a.end()&&mm.find({x.X+y.X,x.Y+y.Y})==mm.end())
            nmm[{x.X+y.X,x.Y+y.Y}]+=z.Y;
    }

    lli ans=0;
    for(auto x:nmm)
        ans=max(ans,x.Y);
    vii ins;
    for(auto x:nmm)
        if(ans==x.Y)
            ins.pb(x.X);
    cerr<<sz(a)<<endl;
    dbg(ins[0]);
    return ins[0];
}

void chk(set<ii> a)
{
    lli n=sz(a);
    bool fl=true;
    dir.clear();
    for(lli i=-2;i<=2;++i)
    for(lli j=-2;j<=2;++j)
        if(abs(i)+abs(j)==3)
             dir.pb({i,j});
    auto init=a;
    while(fl)
    {
        map<ii,lli> mm;
        for(auto x:a)
        for(auto y:dir)
            if(a.find({x.X+y.X,x.Y+y.Y})==a.end())
                mm[{x.X+y.X,x.Y+y.Y}]++;
        fl=false;
        for(auto x:mm)
        if(x.Y>=4)
        {
            a.insert(x.X);
            fl=true;
        }
    }
    
    cout<<n<<" "<<n*n/10<<" "<<sz(a)<<" "<<n*n*1.0/sz(a)<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n;
    
    for(lli i=0;i<=n;++i)
    {
        if(sz(a)>=n)
            break;
        a.insert({i,0});
        if(i%2&&sz(a)<n)
            a.insert({i,3});
    }

    // chk(a);
    for(auto x:a)
        cout<<x.X<<" "<<x.Y<<endl;
}   aryanc403();
    return 0;
}