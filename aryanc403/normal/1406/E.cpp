/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#include <algorithm>
#ifdef ARYANC403
    #include "/home/aryan/codes/PastCodes/template/header.h"
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<iostream>
    #include<bits/stdc++.h>
    #define dbg(args...)
#endif

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
// #define endl "\n"

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

const bool debug=false;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,ans,queries=10000;
    string s;
    vi a;
    vector<bool> vis,vis2;
    lli values;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli queryA(lli x)
{
    queries--;
    if(debug)
    {
        lli cnt=0;
        for(lli j=x;j<=n;j+=x)
            cnt+=vis2[j];
        return cnt;
    }
    cout<<"A "<<x<<endl;
    cin>>x;
    return x;
}

lli queryB(lli x)
{
    assert(x>1);
    queries--;
    if(debug)
    {
        lli cnt=0;
        for(lli j=x;j<=n;j+=x)
        {
            cnt+=vis2[j];
            if(j!=values&&vis2[j])
                vis2[j]=false;
        }
        return cnt;
    }
    cout<<"B "<<x<<endl;
    cin>>x;
    return x;
}

lli queryC(lli n)
{
    cout<<"C "<<n<<endl;
    queries--;
    dbg(values,n,queries);
    if(debug)
        assert(values==n);
    exit(0);
}

void delMultiples(lli x)
{
    for(lli j=x;j<=n;j+=x)
        vis[j]=false;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    if(debug)
    {
        n=100000;
        // values=rnd(1,n);
        values=1033;
    }
    else
    {
        cin>>n;
    }

    vis.resize(n+1,true);
    vis2.resize(n+1,true);

    ans=1;
    vi a;
    for(lli i=2;i*i<=n;++i)
    {
        if(!vis[i])
            continue;
        delMultiples(i);
        queryB(i);
    }

    for(j=2;j*j<=n;++j);
    j--;
    vector<bool> primes(n+1,true);
    for(lli i=2;i*i<=n;++i)
    {
        if(!primes[i])
            continue;
        for(lli j=i*i;j<=n;j+=i)
            primes[j]=false;
        lli p=1;
        while(p*i<=n)
        {
            p*=i;
            if(queryA(p))
                ans=ans*p/__gcd(ans,p);
            else
                break;
        }
    }

    if(ans==2)
    {
        for(lli i=2;2*i<=n;++i)
        {
            if(!vis[i])
                continue;
            if(queryA(2*i))
                ans*=i;
        }
    }
    else if(ans==1)
    {
        vi a;
        for(lli i=2;i<=n;++i)
        {
            if(!primes[i])
                continue;
            if(i*i>n)
                a.pb(i);
        }

        shuffle(all(a),rng);
        // assert(sz(a)<=(queries-1)/2);
        const lli R=100;
        const lli m=sz(a);
        vector<vi> bb(m/R+5);
        for(lli i=0;i<m;++i)
            bb[i/R].pb(a[i]);
        dbg(m,m+m/R,queries);
        lli val=queryA(1);
        for(const auto &v:bb)
        {
            for(auto x:v)
            {
                queryB(x);
                val--;
            }
            if(queryA(1)==val)
                continue;
            for(auto x:v)
            {
                if(queryA(x))
                    ans*=x;
            }
            break;
        }
    }
    else
    {
        for(lli i=2;i<=n;++i)
        {
            if(!vis[i])
                continue;
            if(i*ans>n)
                continue;
            a.pb(i);
        }
        shuffle(all(a),rng);
        dbg(sz(a),(queries-1)/2,queries);
        dbg(ans,values);
        assert(sz(a)<=(queries-1)/2);
        a.resize(min(sz(a),(queries-1)/2));
        for(auto x:a)
        {
            queryB(x);
            if(queryA(x))
                ans=ans*x/__gcd(x,ans);
        }
    }
    dbg(sz(a));
    queryC(ans);
}   aryanc403();
    return 0;
}