/* in the name of Anton */

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
    vi a,b;
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli chk(lli m,bool fl=false)
{
    lli cnt=0;
    for(auto x:a)
    {
        const lli climit=x;
        if(4*x-4*m-1<0)
        {
            if(fl)
                b.pb(0);
            continue;
        }
        x-=m+1;
        lli cur=sqrt(x/(mytype)3.0)-0.25;
        while(3*cur*(cur+1)<=x)
            cur++;
        while(3*cur*(cur+1)>x)
            cur--;
        cur=min(cur,climit);
        cnt+=cur;
        dbg(cur,climit)
        // assert(cur<=climit);
        if(fl)
            b.pb(cur);
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

    cin>>n>>k;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    lli l=-3e18-1e15,r=3e18+1e15;
    while(r-l>1)
    {
        lli m=(l+r)/2;
        if(chk(m)>=k)
            l=m;
        else
            r=m;
    }

    b.clear();
    chk(r,true);
    dbg(sz(b),n)
    priority_queue<ii> pq;
    fo(i,n)
    {
        if(b[i]<a[i])
            pq.push({a[i]-3*b[i]*(b[i]+1)-1,i});
        k-=b[i];
    }
    dbg(r);
    while(k--)
    {
        auto u=pq.top();pq.pop();
        i=u.Y;
        b[i]++;
        if(b[i]<a[i])
            pq.push({a[i]-3*b[i]*(b[i]+1)-1,i});
    }

    dbg(b)

    for(auto x:b)
        cout<<x<<" ";
    cout<<endl;

}   aryanc403();
    return 0;
}