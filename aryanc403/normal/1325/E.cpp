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
const lli N = 1000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi lf;
    vector<vi> e;
    vector<bool> a;
    // priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

map<lli,lli> mm;

lli reduce(lli n){
    mm.clear();
    for(lli i=2;i*i<=n;++i)
    {
        while(n%i==0)
        {
            mm[i]^=1;
            n/=i;
        }
    }

    if(n>1)
        mm[n]^=1;

    n=1;
    for(auto x:mm)
        if(x.Y)
            n*=x.X;
    return n;
}

void addEdge(){
    lli u=-1,v=-1;
    for(auto x:mm){
        if(x.Y==0)
            continue;
        if(u==-1)
            u=x.X;
        else if(v==-1)
            v=x.X;
        else
            assert(false);
    }

    if(v==-1)
        v=1;
    e[u].pb(v);
    e[v].pb(u);
}

lli ans;

void djk(lli st){
    if(e[st].empty())
        return;
    queue<ii> pq;
    pq.push(mp(st,-1));
    pq.push(mp(-1,-1));
    dbg(st);
    lli cnt=0;
    vi d(N+1,INF);
    bool fl=true;

    while(!pq.empty()){
        auto u=pq.front();pq.pop();
        dbg(u,cnt);
        if(u.X==-1){
            pq.push(mp(-1,-1));
            cnt++;
            if(fl)
                break;
            fl=true;
            continue;
        }

        if(d[u.X]<=cnt)
        {
            ans=min(ans,cnt+d[u.X]);
            continue;
        }

        fl=false;
        d[u.X]=cnt;
        for(auto x:e[u.X])
            if(x!=u.Y)
                pq.push(mp(x,u.X));
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    ans=INF;

    e.resize(N+1);
    a.resize(N+1,false);

    cin>>n;
    while(n--)
    {
        cin>>in;
        in=reduce(in);
        dbg(in);
        if(in==1){
            cout<<1<<endl;
            return 0;
        }

        if(!a[in])
        {
            a[in]=true;
            addEdge();
        }
        else
            ans=min(ans,2LL);
    }

    // dbg(a);

    for(lli i=1;i<=1000;++i)
        djk(i);

    if(ans==INF)
        ans=-1;
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}