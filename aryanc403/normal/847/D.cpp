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

const lli INF = 3e9;

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
    vi a,b;
    map<lli,lli> mm;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli fnd(lli x,lli n)
{
    lli i;
    lli cnt=0;
    fo(i,n)
        cnt+=(a[i]<=x);
    return cnt;
}

void upd(lli x,lli v)
{
    x++;
    while(x<=INF)
    {
        mm[x]+=v;
        x+=x&(-x);
    }
}

lli query(lli x)
{
    x++;
    lli cnt=0;
    while(x>0)
    {
        cnt+=mm[x];
        x-=x&(-x);
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli t;
    cin>>n>>t;
    a.clear();a.reserve(n);
    a.pb(INF+1);
    repA(i,1,n)
    {
        cin>>in;
        a.pb(max(0LL,in-i));
    }
    n++;
    b=a;
    b.pb(0);
    sort(all(b));
    b.erase(unique(all(b)),b.end());

    for(auto x:a)
        upd(x,1);

    lli ans=0;
    for(auto x:b)
    {
        while(n>=1&&n>t-x)
        {
            n--;
            upd(a[n],-1);
        }
        ans=max(ans,query(x));
    }
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}