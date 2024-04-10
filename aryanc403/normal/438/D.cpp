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
    lli m;
    string s;
    vi a,b;
    lli f[4*maxN+5];
    lli sum[4*maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli typ1(lli id,lli l,lli r,lli L,lli R)
{
    if(r<L||R<l)
        return 0;
    if(L<=l&&r<=R)
        return sum[id];
    lli m=(l+r)/2;
    return typ1(2*id,l,m,L,R)+typ1(2*id+1,m+1,r,L,R);
}

void typ2(lli id,lli l,lli r,lli L,lli R,lli x)
{
    if(r<L||R<l||f[id]<x)
        return;

    if(l==r)
    {
        sum[id]+=(a[l]%x)-a[l];
        a[l]%=x;
        f[id]=a[l];
        return;
    }

    lli m=(l+r)/2;
    typ2(2*id,l,m,L,R,x);
    typ2(2*id+1,m+1,r,L,R,x);

    f[id]=max(f[2*id],f[2*id+1]);
    sum[id]=sum[2*id]+sum[2*id+1];
}

void typ3(lli id,lli l,lli r,lli pos,lli val)
{
    if(r<pos||pos<l)
        return;
    sum[id]+=val-a[pos];
    if(l==r)
    {
        a[pos]=f[id]=val;
        return;
    }
    lli m=(l+r)/2;
    typ3(2*id,l,m,pos,val);
    typ3(2*id+1,m+1,r,pos,val);
    f[id]=max(f[2*id],f[2*id+1]);
}

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        sum[id]=f[id]=a[l];
        return;
    }
    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    f[id]=max(f[2*id],f[2*id+1]);
    sum[id]=sum[2*id]+sum[2*id+1];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    a.clear();a.reserve(n);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    build(1,1,n);
    while(m--)
    {
        cin>>T>>l>>r;

        if(T==1)
            cout<<typ1(1,1,n,l,r)<<endl;
        else if(T==2)
        {
            lli k;
            cin>>k;
            b.clear();
            typ2(1,1,n,l,r,k);
            for(auto x:b)
                typ3(1,1,n,x,a[x]%k);
        }
        else
            typ3(1,1,n,l,r);
    }

}   aryanc403();
    return 0;
}