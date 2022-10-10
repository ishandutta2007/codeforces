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
    vi dp,col,vis,par;
    vector<vi> e,er;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dijk()
{
    queue<lli> q;
    q.push(2*n-2);
    q.push(2*n-1);
    q.push(-1);
    int cnt=0;
    bool fl=false;
    while(!q.empty())
    {
        const auto u=q.front();
        q.pop();
        if(u==-1)
        {
            cnt++;
            if(fl)
                break;
            fl=true;
            q.push(-1);
            continue;
        }

        if(dp[u/2]<=cnt)
            continue;

        if(u/2!=n-1)
        {
            if(col[u/2]==-1||col[u/2]!=u%2)
            {
                col[u/2]=!(u&1);
                continue;
            }
        }

        dbg(u,cnt,u%2);
        dp[u/2]=cnt;
        col[u/2]=u%2;
        fl=false;
        for(auto x:er[u])
            q.push(x);
    }

    dbg(dp);
}

lli dijk2()
{
    queue<lli> q;
    vi dp(n,INF);
    int cnt=0;
    bool fl=false;
    q.push(0);
    q.push(-1);
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        dbg(u,cnt);
        if(u==-1)
        {
            cnt++;
            if(fl)
                break;
            fl=true;
            q.push(-1);
            continue;
        }

        if(dp[u]<=cnt)
            continue;
        fl=false;
        dp[u]=cnt;
        dbg(u,2*u+col[u])
        u=2*u+col[u];
        dbg(e[u])
        for(auto x:e[u])
            q.push(x);
    }
    dbg(dp);
    if(dp[n-1]==INF)
        return -1;
    return dp[n-1];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    dp.resize(n,INF);
    vis.resize(2*n,-1);
    par.resize(2*n,-1);
    e.resize(2*n);
    er.resize(2*n);

    while(m--)
    {
        lli t;
        cin>>u>>v>>t;
        if(u==v)
            continue;
        u--;v--;
        u=2*u+t;
        v*=2;
        e[u].push_back(v/2);
        er[v].push_back(u);
        er[v+1].push_back(u);
    }

    col.resize(n,-1);
    dijk();
    for(auto &x:col)
        x=max(x,0LL);
    cout<<dijk2()<<endl;
    for(auto x:col)
        cout<<x;
    cout<<endl;
}   aryanc403();
    return 0;
}