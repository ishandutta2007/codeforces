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
typedef long double ld;
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
#define bcnt(x) __builtin_popcount(x)

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<ld> a,ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

// void go(lli msk,ld p,ld sum)
// {
//     if(bcnt(msk)==k)
//     {
//         for(lli j=0;j<n;++j)
//         {
//             if(msk&(1<<j))
//                 ans[j]+=p;
//         }
//         return;
//     }

//     p*=1/(1-sum);
//     for(lli j=0;j<n;++j)
//     {
//         if(msk&(1<<j))
//             continue;
//         go(msk|(1<<j),p*a[j],sum+a[j]);    
//     }
// }

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cout<<std::fixed<<std::setprecision(10);
// cin>>T;while(T--)
{

    cin>>n>>k;
    a.resize(n);
    ans.resize(n);
    
    for(auto &x:a)
        cin>>x;
    // go(0,1,0);

    vi msks(1<<n);
    vector<ld> dp(1<<n);
    dp[0]=1;

    iota(all(msks),0);
    sort(all(msks),[&](const lli x,const lli y){
        return bcnt(x)<bcnt(y);
    });
    dbg(msks);
    dbg(ans);
    for(auto msk:msks)
    {
        auto p=dp[msk];
        if(bcnt(msk)==k)
        {
            for(lli j=0;j<n;++j)
            {
                if(msk&(1<<j))
                    ans[j]+=p;
            }
            continue;
        }
        ld sum=0;
        for(lli j=0;j<n;++j)
        {
            if(msk&(1<<j))
                sum+=a[j];
        }
        
        if(abs(1-sum)<1e-9)
        {
            for(lli j=0;j<n;++j)
            {
                if(msk&(1<<j))
                    ans[j]+=p;
            }
            continue;
        }

        p*=1/(1-sum);
        for(lli j=0;j<n;++j)
        {
            if(msk&(1<<j))
                continue;
            dp[msk|(1<<j)]+=p*a[j];
        }
    }

    fo(i,n)
        cout<<ans[i]<<" ";

}   aryanc403();
    return 0;
}