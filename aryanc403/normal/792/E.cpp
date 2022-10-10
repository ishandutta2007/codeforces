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
// typedef int lli;
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
const lli N = 40000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    bool fl=true;
    string s;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void merge(vi &a,vi &b)
{
    if(fl&&a.empty())
    {
        a.swap(b);
        fl=false;
        return;
    }

    fl=false;
    lli i=0,j=0;
    vi c;
    while(i<sz(a)&&j<sz(b))
    {
        if(a[i]==b[j])
        {
            c.pb(a[i]);
            i++;j++;
            continue;
        }

        if(a[i]<b[j])
            i++;
        else
            j++;
    }
    a.swap(c);
}

void solve(vi &a,lli n)
{
    for(lli i=1;i<=n/i;++i)
    {
        if(n/i>=N)
        {
            a.pb(n/i);
            if(n%i==0)
                a.pb(n/i-1);
        }
        // lli d=(n+i)/(i+1);
        // if(d*i<=n)
        //     a.pb(i);
    }
    
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    // dbg(a);
    return;
}

lli count(const vi &a,lli y)
{
    dbg(y);
    lli cnt=0;
    for(auto x:a)
    {
        lli d=(x+y)/(y+1);
        cnt+=d;
        if(d*y>x)
        {
            dbg(d,y,x);
            return -1;
        }
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

    // cin>>n;
    scanf("%d ",&n);
    vi a,c;
    fo(i,n)
    {
        // cin>>in;s
        scanf("%d ",&in);
        a.pb(in);
    }

    // sort(all(a));
    c=a;
    sort(all(c));
    c.erase(unique(all(c)),c.end());
    // mn=max(1,mn-5);
    // mx++;
    // dbg(a);
    // for(auto x:a)
    //     cerr<<x<<" ";
    // assert(a[0]!=324871127);
    vi ans;
    for(auto x:c)
    {
        vi b;
        solve(b,x);
        merge(ans,b);
    }

    lli j=-1;
    i=N;
    while(j==-1)
    {
        if(ans.empty())
            j=count(a,i--);
        else
        {
            j=count(a,ans.back());
            ans.pop_back();
        }
    }
    cout<<j<<endl;
}   aryanc403();
    return 0;
}