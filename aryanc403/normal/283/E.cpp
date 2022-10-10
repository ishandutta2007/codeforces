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
#define sz(x) (int)(x).size()
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
const lli maxN = 100000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,ans;
    string s;
    vi a;
    vii q[maxN+5];
    lli f[4*maxN+5],L[4*maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void flp(lli id,lli l,lli r)
{
    if(id>4*maxN)
        return;
    f[id]=(r-l+1)-f[id];
    L[id]^=1;
}

void push(lli id,lli l,lli r)
{
    if(!L[id])
        return;

    lli m=(l+r)/2;
    flp(2*id,l,m);
    flp(2*id+1,m+1,r);
    L[id]=0;
}

void update(lli id,lli l,lli r,lli L,lli R)
{
    if(r<L||R<l)
        return;
    push(id,l,r);
    if(L<=l&&r<=R)
    {
        flp(id,l,r);
        return;
    }
    lli m=(l+r)/2;
    update(2*id,l,m,L,R);
    update(2*id+1,m+1,r,L,R);
    f[id]=f[2*id]+f[2*id+1];
}

lli query(lli id,lli l,lli r,lli L,lli R)
{
    if(L>R||r<L||R<l)
        return 0;
    push(id,l,r);
    if(L<=l&&r<=R)
        return f[id];
    lli m=(l+r)/2;
    return query(2*id,l,m,L,R)+query(2*id+1,m+1,r,L,R);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    a.pb(-INF);
    a.pb(INF);

    sort(a.begin(),a.end());
    ans-=n*(n-1)*(n-2)/6;
    dbg(a);
    while(k--)
    {
        cin>>l>>r;
        l=lower_bound(all(a),l)-a.begin();
        r=upper_bound(all(a),r)-a.begin();r--;
        q[l].pb({l,r});
        q[r+1].pb({l,r});
    }

    repA(i,1,n)
    {
        lli cnt=0;
        for(auto x:q[i])
            update(1,1,n,x.X,x.Y);
        cnt+=query(1,1,n,1,i-1);
        cnt+=(n-i)-query(1,1,n,i+1,n);
        dbg(i,cnt,query(1,1,n,1,i-1));
        cnt=n-1-cnt;
        ans+=cnt*(n-cnt-1);
    }

    ans/=2;
    dbg(ans);
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}