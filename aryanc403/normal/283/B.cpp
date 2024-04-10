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
const lli maxN = 200000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    lli cyc[2][maxN+5];
    lli dp[2][maxN+5];
    bool cur[2][maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli dfs(lli u,lli x)
{
    if(u<=0||u>n)
        return -1;
    if(cyc[x][u])
        return cyc[x][u];
    if(cur[x][u])
    {
        cyc[x][u]=1;
        return 1;
    }

    cur[x][u]=true;
    if(x==1)
        cyc[x][u]=dfs(u+a[u],1-x);
    else
        cyc[x][u]=dfs(u-a[u],1-x);
    cur[x][u]=false;
    return cyc[x][u];
}

lli dfs2(lli u,lli x)
{
    if(u<=0||u>n)
        return 0;

    if(u==1)
    {
        assert(x==0);
        return -i;
    }

    if(cur[x][u])
        return dp[x][u];

    cur[x][u]=true;
    lli &ans=dp[x][u];

    if(x==1)
        ans=dfs2(u+a[u],1-x);
    else
        ans=dfs2(u-a[u],1-x);
    ans+=a[u];
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);a.pb(0);
    fo(i,n-1)
    {
        cin>>in;
        a.pb(in);
    }
    dbg(a);
    // 1 for add.
    cyc[1][1]=1;// inf loop.
    // 0 for sub.
    cyc[0][1]=-1;// no loop.

    repA(i,2,n)
    {
        dfs(i,1);
        dfs(i,0);
    }

    repA(i,1,n-1)
    {
        if(cyc[0][i+1]==1)
        {
            cout<<-1<<endl;
            continue;
        }
        // cout<<endl;
        cout<<i+dfs2(i+1,0)<<endl;
    }

}   aryanc403();
    return 0;
}