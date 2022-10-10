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
    return a.X<b.X||(a.X==b.X&&a.Y>b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b;
    map<lli,lli> df;
    vi f,lz;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        f[id]=-df[b[l]];
        return;
    }

    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    f[id]=max(f[2*id],f[2*id+1]);
}

void update(lli id,lli l,lli r,lli pos,lli v)
{
    if(r<pos)
        return;
    if(pos<=l)
    {
        lz[id]+=v;
        f[id]+=v;
        return;
    }

    lli m=(l+r)/2;
    update(2*id,l,m,pos,v);
    update(2*id+1,m+1,r,pos,v);
    f[id]=max(f[2*id],f[2*id+1])+lz[id];
}

void update(lli p,lli v)
{
    p=lower_bound(all(b),p)-b.begin();
    update(1,1,n,p,v);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli p;
    cin>>n>>m>>p;

    vii wp;

    fo(i,n)
    {
        lli at,c;
        cin>>at>>c;
        wp.pb({at,c});
    }

    sort(all(wp),cmp);
    repD(i,n-2,0)
        wp[i].Y=min(wp[i].Y,wp[i+1].Y);

    dbg(wp);
    
    b.pb(-INF);
    b.pb(INF);
    
    fo(i,m)
    {
        lli at,c;
        cin>>at>>c;
        b.pb(at);
        if(df[at])
            df[at]=min(df[at],c);
        else
            df[at]=c;
    }

    sort(all(b));
    b.erase(unique(all(b)),b.end());
    
    n=sz(b)-2;
    f.resize(4*n+10,0);
    lz.resize(4*n+10,0);
    build(1,1,n);
    dbg(df);

    vector<pair<lli,ii>> mon;
    fo(i,p)
    {
        lli x,y,z;
        cin>>x>>y>>z;
        mon.pb({x,{y,z}});
    }

    sort(all(mon),[](const pair<lli,ii> &a,const pair<lli,ii> &b){
        return a.X<b.X;
    });

    lli ans=-INF;
    i=0;
    ans=-wp[0].Y+f[1];
    dbg(i);
    dbg(mon);
    dbg(ans);
    for(const auto &v:mon)
    {
        while(i<sz(wp)&&wp[i].X<=v.X)
            i++;
        if(i==sz(wp))
            break;
        update(v.Y.X+1,v.Y.Y);
        ans=max(ans,f[1]-wp[i].Y);
    }
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}