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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,d1,dn;
    vector<vi> e;
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool cmp(const lli &a,const lli &b)
{
    return d1[a]-dn[a]>d1[b]-dn[b];
}

void djk(lli u,vi &d)
{
    d.clear();
    d.resize(n+1,INF);
    pq.push({0,u});
    while(!pq.empty())
    {
        auto v=pq.top();pq.pop();
        if(d[v.Y]<=v.X)
            continue;
        d[v.Y]=v.X;
        for(auto x:e[v.Y])
            pq.push({v.X+1,x});
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    e.resize(n+1,vi(0));
    fo(i,k)
    {
        cin>>in;
        a.pb(in);
    }

    fo(i,m)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }

    djk(1,d1);
    djk(n,dn);
    
    lli ans=0;

    sort(all(a),cmp);

    lli mn=-INF;
    for(auto x:a)
    {
        dbg(x,d1[x],mn);
        ans=max(ans,mn+d1[x]);
        mn=max(mn,dn[x]);
    }
    ans++;
    ans=min(ans,d1[n]);
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}