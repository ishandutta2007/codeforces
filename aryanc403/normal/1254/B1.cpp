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
    vi aa,a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void get(vi &b,const vi &a)
{
    lli sum=0;
    b.pb(0);
    for(auto x:a)
    {
        sum+=x;
        b.pb(sum+b.back());
    }
    b.pop_back();
}

lli mini(vi &a)
{
    const lli n=sz(a);

    vi b,c;
    get(b,a);
    reverse(all(a));
    get(c,a);
    reverse(all(c));
    dbg(a,b,c);

    lli ans=INF;
    lli i=0;
    fo(i,n)
        ans=min(ans,b[i]+c[i]);
    return ans;
}

lli solve(lli k)
{
    vi a;
    for(auto x:aa)
        a.pb(x%k);

    // dbg(k,a);
    lli ans=0,cnt=0;
    lli i=0;
    const lli n=sz(a);

    while(i<n)
    {
        cnt=0;
        while(i<n&&a[i]==0)
            i++;
        if(i==n)
            break;
        vi b;
        j=i;
        while(j<n&&cnt<k)
        {
            cnt+=a[j];
            b.pb(a[j]);
            j++;
        }

        dbg(k,cnt,i,j,a);
        b.back()-=cnt%k;
        ans+=mini(b);
        j--;
        a[j]=cnt%k;
        i=j;
    }

    dbg(k,ans);
    return ans;
}

void debug()
{
    cin>>n;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
        cnt+=in;
    }

    dbg(mini(a));
    exit(0);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    // debug();
    cin>>n;
    aa.clear();aa.reserve(n);
    // lli sum=200560490130LL;
    fo(i,n)
    {
        // in=min(1000000LL,sum);        sum-=in;
        cin>>in;
        aa.pb(in);
        cnt+=in;
    }

    if(cnt==1)
    {
        cout<<-1<<endl;
        return 0;
    }

    lli ans=INF;
    for(lli i=2;i*i<=cnt;++i)
    {
        if(cnt%i)
            continue;
        ans=min(ans,solve(i));
        while(cnt%i==0)
            cnt/=i;
    }

    if(cnt>1)
        ans=min(ans,solve(cnt));
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}