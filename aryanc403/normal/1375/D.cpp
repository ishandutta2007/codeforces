/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

typedef int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
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
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli findMex()
{
    vector<bool> vis(n+2,false);
    for(auto x:a)
        vis[min(x,n+1)]=true;
    for(lli i=0;i<=n+1;++i)
    {
        if(vis[i])
            continue;
        return i;
    }
    assert(false);
}

bool chk()
{
    lli pvr=0;
    for(auto x:a)
    {
        if(pvr>x)
            return false;
        pvr=x;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    vi ans;

    lli l=0,r=n;

    while(l<r)
    {
        const lli k=findMex();
        while(l<r&&a[l]==l)
            l++;
        while(l<r&&a[r-1]==r)
            r--;
        dbg(a,l,r);
        if(l>=r)
            break;

        if(k==r)
        {
            a[r-1]=k;
            ans.pb(r-1);
            continue;
        }

        if(k==l)
        {
            a[l]=k;
            ans.pb(l);
            continue;
        }

        a[k]=k;
        ans.pb(k);
    }

    cout<<sz(ans)<<endl;
    for(auto x:ans)
        cout<<x+1<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}