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

const lli mod = 998244353LL;
const lli N = 2000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b;
    vector<vi> c;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void mult(vi &a,const vi &b,const vi &c)
{
    a.clear();
    const lli n=sz(b),m=sz(c);
    lli i,j;
    a.resize(n+m,0);
    fo(i,n)
    fo(j,m)
        a[i+j]=(a[i+j]+b[i]*c[j]%mod)%mod;
}

void solve(vi &a,lli l,lli r)
{
    a.clear();
    if(l==r)
    {
        a=c[l];
        return;
    }

    lli m=(l+r)/2;
    vi b,d;
    solve(b,l,m);
    solve(d,m+1,r);
    mult(a,b,d);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;

    a.clear();a.reserve(n+2);

    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    a.pb(a[1]);
    a[0]=a[n];
    // b=a;
    // b.pb(-INF);b.pb(INF);
    // sort(all(b));
    // // dbg(b);
    // b.erase(unique(all(b)),b.end());
    // // dbg(b);

    // for(auto &x:a)
    //     x=lower_bound(all(b),x)-b.begin();
    // // dbg(a);

    repA(i,1,n)
    {
        if(a[i]==a[i-1])
            c.pb({0,k,0});
        else
            c.pb({1,k-2,1});
    }

    // solve();

    // for(auto x:c)
    //     dbg(x);

    vi sol;
    solve(sol,0,n-1);
    dbg(sol);
    dbg(sz(sol));

    lli ans=0;
    repA(i,n+1,3*n-1)
        ans+=sol[i];
    ans%=mod;
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}