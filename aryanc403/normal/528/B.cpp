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
const lli maxN = 2*200000L+4;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vii a;
    vi b;
    lli f[4*maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli query(lli id,lli l,lli r,lli L)
{
    if(r<L||L<l)
        return -INF;
    if(l==r)
        return f[id];
    lli m=(l+r)/2;
    return max({f[id],query(2*id,l,m,L),query(2*id+1,m+1,r,L)});
}

lli query(lli v)
{
    v=lower_bound(all(b),v)-b.begin();
    return query(1,0,n,v);
}

void update(lli id,lli l,lli r,lli R,lli v)
{
    if(R<l)
        return;
    if(r<=R)
    {
        f[id]=max(f[id],v);
        return;
    }
    lli m=(l+r)/2;
    update(2*id,l,m,R,v);
    update(2*id+1,m+1,r,R,v);
}

void update(lli p,lli v)
{
    p=lower_bound(all(b),p)-b.begin();
    update(1,0,n,p,v);
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

    fo(i,n)
    {
        lli w;
        cin>>x>>w;
        a.pb({x,w});
        b.pb(x+w);
        b.pb(x-w);
    }

    b.pb(-INF);b.pb(INF);
    sort(all(b));b.erase(unique(all(b)),b.end());
    n=sz(b);

    sort(all(a));
    reverse(all(a));

    dbg(a);

    lli ans=0;
    for(auto x:a)
    {
        lli k=1+query(x.X+x.Y);
        update(x.X-x.Y,k);//-inf to 
        ans=max(ans,k);
        dbg(x,k);
    }

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}