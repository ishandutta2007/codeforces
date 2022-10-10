/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

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
    vector<vi> a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli cst(lli l,lli r)
{
    l--;
    return (a[r][r]+a[l][l]-a[l][r]-a[r][l])/2;
}

void DnC(vi &pvr,vi &dp,lli l,lli r,lli L,lli R)
{
    if(l>r)
        return;
    lli m=(l+r)/2,opt=L;
    dp[m]=INF;
    for(lli i=L;i<=R&&i<=m;++i)
    {
        const lli val=pvr[i-1]+cst(i,m);
        if(val<dp[m])
        {
            dp[m]=val;
            opt=i;
        }
    }
    dbg(m,opt);
    DnC(pvr,dp,l,m-1,L,opt);
    DnC(pvr,dp,m+1,r,opt,R);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    a.resize(n+1,vi(n+1));
    repA(i,1,n) repA(j,1,n)
    {
        cin>>a[i][j];
        a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    }

    vector<vi> dp(2,vi(n+1,INF));
    dp[0][0]=dp[1][0]=0;
    dbg(dp);
    for(int i=1;i<=k;++i)
    {
        DnC(dp[(i+1)&1],dp[i&1],1,n,1,n);
        dbg(dp);
    }
    cout<<dp[k&1][n]<<endl;
    // dbg(dp[n]);
}   aryanc403();
    return 0;
}