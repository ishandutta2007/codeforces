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
    vector<vi> a;
    vi dp;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    a.clear();a.resize(n,vi(m+1,0));
    dp.resize(m+2,0);

    fo(i,n)
    repA(j,1,m)
        cin>>a[i][j];
    
    {
        vi &b=a[0];
        repA(i,1,m)
            b[i]+=b[i-1];
        repA(i,1,m-k+1)
            dp[i]=b[i+k-1]-b[i-1];
    }

    bool fl=true;
    for(const vi &b:a)
    {
        if(fl)
        {
            dbg(dp);
            fl=false;
            continue;
        }

        vi cur(m+2,0),prf(m+2,0),suf(m+2,0),sum(m+2,0);

        repA(i,1,m)
            sum[i]=sum[i-1]+b[i];

        prf[0]=dp[0];
        repA(i,1,m-k+1)
            prf[i]=max(prf[i-1],dp[i]+sum[i+k-1]-sum[i-1]);
        
        repD(i,m-k+1,1)
            suf[i]=max(suf[i+1],dp[i]+sum[i+k-1]-sum[i-1]);
        
        repA(i,1,m-k+1)
        {
            lli &ans=cur[i];
            ans=max(ans,suf[i+k]+sum[i+k-1]-sum[i-1]);
            if(i>=k)
                ans=max(ans,prf[i-k]+sum[i+k-1]-sum[i-1]);
            for(lli j=max(1LL,i-k);j<=m-k+1&&j<i+k;++j)    
                ans=max(ans,dp[j]+sum[max(i+k-1,j+k-1)]-sum[min(i,j)-1]);
            // dbg(i,ans);
        }
        dbg(b);
        dbg(prf)
        dbg(suf)
        dp.swap(cur);
        dbg(sum);
        dbg(dp);
    }

    lli ans=0;
    for(auto x:dp)
        ans=max(x,ans);
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}