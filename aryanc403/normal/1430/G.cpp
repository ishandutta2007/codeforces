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
const lli N = 18L;
const lli L = 1LL<<N;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,dis,stree,ans;
    vector<vi> e;
    bool vis[L];
    lli dp[N+1][L],val[L],bf[L];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p)
{
    if(dis[u]&(1LL<<p))
        return;
    if(u!=p)
    {
        dis[u]|=(1LL<<p);
        stree[p]|=(1LL<<u);
    }
    for(auto x:e[u])
        dfs(x,p);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n>>m;
    const lli lim = (1LL<<n);
    a.resize(n);
    e.resize(n);
    dis.resize(n);
    stree.resize(n);
    ans.resize(n);

    while(m--)
    {
        lli w;
        cin>>u>>v>>w;
        u--;v--;
        a[u]+=w;
        a[v]-=w;
        e[u].pb(v);
    }

    dbg(a);
    fo(i,n)
        dfs(i,i);

    fo(i,n)
    fo(j,lim)
        dp[i][j]=INF;
    // dbg(dis,dp[0][0]);
    for(lli i=0;i<lim;++i)
    {
        bool &fl=vis[i];
        fl=true;
        for(lli j=0;j<n;++j)
        {
            if((i&(1LL<<j))==0)
                continue;
            if(i&dis[j])
                fl=false;
            val[i]+=a[j];
            bf[i]|=stree[j];
        }
        if(fl&&(bf[i]==0))
            dp[0][i]=0;
        // dbg(0,i,dp[0][i]);
        // dbg(fl,i);
    }

    int mx=0;
    for(lli i=1;i<=n;++i)
    {
        auto cur=dp[i],pvr=dp[i-1];
        for(lli msk=0;msk<lim;++msk)
        {
            if(pvr[msk]==INF)
                continue;
            const lli imsk=(~msk)&(lim-1);
            // dbg(msk,imsk);
            for(lli sb = imsk; sb > 0; sb = (sb-1) & imsk)
            {
                if(!vis[sb])
                    continue;
                if(bf[sb]!=(msk&bf[sb]))
                    continue;
                dbg(msk,sb,i,cur[msk|sb],pvr[msk]+i*val[sb]);
                cur[msk|sb]=min(cur[msk|sb],pvr[msk]+i*val[sb]);
            }
            // dbg(i,msk,cur[msk]);
        }
        mx++;
        dbg(i,dp[i][lim-1]);
        if(cur[lim-1]<INF)
            break;
    }

    dbg(dp[0][8]);
    dbg(dp[1][28]);
    dbg(dp[2][30]);
    dbg(dp[3][31]);

    dbg(dp[mx][lim-1]);
    for(lli i=mx,msk=lim-1;i>0;--i)
    {
        auto cur=dp[i],pvr=dp[i-1];
        lli fl=-1;
        for(lli sb = msk; sb > 0; sb = (sb-1) & msk)
        {
            if(!vis[sb])
                continue;
            if(bf[sb]!=((msk^sb)&bf[sb]))
                continue;
            if(cur[msk]!=pvr[msk^sb]+i*val[sb])
                continue;
            fl=sb;
            break;
        }
        assert(fl!=-1);
        for(lli j=0;j<n;++j)
        {
            if(fl&(1LL<<j))
                ans[j]=i;
        }
        msk^=fl;
        if(i==1)
            assert(vis[msk]);
    }

    dbg(ans);
    for(auto x:ans)
        cout<<x<<" ";
}   aryanc403();
    return 0;
}