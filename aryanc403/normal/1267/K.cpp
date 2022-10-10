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
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    lli fac[25];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli nCr(lli n,lli r)
{
    if(r<0||n<0||n<r)
        return 0;
    // dbg(n,r);
    // assert(r<=n);
    lli ans=1;
    ans*=fac[n];
    ans/=fac[r];
    ans/=fac[n-r];
    return ans;
}

lli solve(map<lli,lli> a,lli n)
{
    lli ans=1;
    for(auto it=a.rbegin();it!=a.rend();++it)
    {
        ans*=nCr(n-it->X,it->Y);
        // dbg("nCr",(n-it->X),it->Y);
        n-=it->Y;
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
fac[0]=1;
repA(i,1,20)
    fac[i]=i*fac[i-1];
// dbg(fac[20]);
cin>>T;while(T--)
{

    cin>>n;
    map<lli,lli> a;
    a.clear();
    i=1;
    while(n)
    {
        a[n%i]++;
        n/=i;
        i++;
    }

    n=i-1;

    // dbg(a,n);

    lli ans=0;
    ans+=solve(a,n);
    a[0]--;n--;

    // dbg("add");

    ans-=solve(a,n);
    ans--;

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}