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
    vector<vi> e,er;
    vi d,a;
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void djk()
{
    d.clear();
    d.resize(n+1,INF);
    pq.push({0,a.back()});
    while(!pq.empty())
    {
        auto u=pq.top();pq.pop();
        if(d[u.Y]<=u.X)
            continue;
        d[u.Y]=u.X;
        for(auto x:er[u.Y])
            pq.push({u.X+1,x});
    }
    dbg(d);
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
    er.resize(n+1);
    
    fo(i,m)
    {
        cin>>u>>v;
        e[u].pb(v);
        er[v].pb(u);
    }

    cin>>k;
    fo(i,k)
    {
        cin>>in;
        a.pb(in);
    }

    djk();

    lli mn=0,mx=0;
    bool fl=false;
    dbg(a);

    // const lli s=a[i],cur=a[i+1];
    

    fo(i,k-1)
    {
        const lli pvr=a[i],cur=a[i+1];
        if(d[pvr]!=d[cur]+1)
        {
            mn++;
            mx++;
            fl=true;
            continue;
        }

        // if(!fl)
        //     continue;

        for(auto x:e[pvr])
        {
            if(x==cur)
                continue;
            if(d[x]==d[cur])
            {
                mx++;
                break;
            }
        }
    }
    cout<<mn<<" "<<mx<<endl;
}   aryanc403();
    return 0;
}