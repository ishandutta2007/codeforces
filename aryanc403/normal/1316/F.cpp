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

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
const lli N = 600000L+4;

struct node{
    lli ans,fw,bw,s;
    node():ans(0),fw(0),bw(0),s(1){};
};

node merge(const node &l,const node &r)
{
    node a;
    a.ans=l.ans*r.s+r.ans*l.s+l.fw*r.bw;a.ans%=mod;
    a.fw=l.fw+r.fw*l.s;a.fw%=mod;
    a.bw=l.bw*r.s+r.bw;a.bw%=mod;
    a.s=l.s*r.s%mod;
    return a;
}
    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    vii gt;
    vector<bool> pt;
    node f[4*N+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n&1)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

lli fnd(ii x)
{
    lli it=lower_bound(all(gt),x)-gt.begin();
    return it;
}

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        if(pt[l])
        {
            f[id].fw=f[id].bw=gt[l].X;
            f[id].s=2;
        }
        else
        {
            f[id].fw=f[id].bw=0;
            f[id].s=1;
        }
        return;
    }

    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    f[id]=merge(f[2*id],f[2*id+1]);
}

void update(lli id,lli l,lli r,lli pos)
{
    if(r<pos||pos<l)
        return;
    if(l==r)
    {
        if(pt[l])
        {
            f[id].fw=f[id].bw=gt[l].X;
            f[id].s=2;
        }
        else
        {
            f[id].fw=f[id].bw=0;
            f[id].s=1;
        }
        return;
    }

    lli m=(l+r)/2;
    update(2*id,l,m,pos);
    update(2*id+1,m+1,r,pos);
    f[id]=merge(f[2*id],f[2*id+1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;

    const lli den=po(po(2,n),mod-2);

    a.clear();a.reserve(n);
    a.pb(-1);

    gt.pb({0,0});
    gt.pb({INF,0});
    

    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
        gt.pb({in,i});
    }

    lli q;
    cin>>q;
    vii qur;

    while(q--)
    {
        cin>>x>>in;
        qur.pb({x,in});
        gt.pb({in,x});
    }

    sort(all(gt));
    gt.erase(unique(all(gt)),gt.end());
    dbg(gt);

    for(auto x:gt)
        pt.pb(a[x.Y]==x.X);

    dbg(pt);

    build(1,1,sz(gt)-1);
    dbg(f[1].ans);
    cout<<(f[1].ans*den)%mod<<endl;

    for(auto u:qur)
    {
        const lli x=u.X,v=u.Y;
        lli cur=fnd({a[x],x});
        assert(pt[cur]==1);
        pt[cur]=0;
        update(1,1,sz(gt)-1,cur);

        a[x]=v;
        cur=fnd({a[x],x});
        assert(pt[cur]==0);
        pt[cur]=1;
        update(1,1,sz(gt)-1,cur);

        dbg(f[1].ans);
        cout<<(f[1].ans*den)%mod<<endl;
    }

}   aryanc403();
    return 0;
}