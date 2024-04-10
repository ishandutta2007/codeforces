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
const lli N = 14L;
#define bcnt(x) __builtin_popcount(x)

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s[N];
    vector<long long int> dp[1LL<<N][N];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    fo(i,n)
        cin>>s[i];
    
    for(lli i=1;i<(1<<n);++i)
    for(lli j=0;j<n;++j)
        dp[i][j].resize((1<<(bcnt(i)))>>1,0);

    for(lli j=0;j<n;++j)
        dp[1<<j][j][0]=1;
    
    for(lli used=1;used<(1<<n);++used)
    {
        const lli len=bcnt(used)-2;
        if(len==-1)
            continue;
        vi c;
        for(lli j=0;j<n;++j)
            if(used&(1<<j))
                c.pb(j);
        for(const auto &lst:c)
        for(const auto &k:c)
        {
            if(k==lst)
                continue;
            const lli fl=(s[lst][k]-'0'?(1<<len):0);
            for(lli msk=0;msk<(1<<len);++msk)
                    dp[used][lst][msk|fl]+=dp[used^(1<<lst)][k][msk];
        }
    }
    
    for(lli i=0;2*i<(1<<n);++i)
    {
        long long int ans=0;
        for(lli j=0;j<n;++j)
            ans+=dp[(1<<n)-1][j][i];
        cout<<ans<<endl;
        // break;
    }
    

}   aryanc403();
    return 0;
}