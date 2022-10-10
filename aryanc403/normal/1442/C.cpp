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

const lli mod = 998244353LL;
const lli logN = 18;

lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n%2)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<vii> e,e2;
    vii d2;

void run(const vector<vii> &e)
{
    auto cmp=[](const ii &a,const ii &b){
        return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));
    };
    priority_queue < ii , vector < ii > , decltype(cmp) > pq(cmp);
    pq.push({0,0});
    dbg(n*logN);
    vi dist(logN*n,INF);
    while(!pq.empty())
    {
        auto d=pq.top().X,u=pq.top().Y;
        // dbg(d,u);
        pq.pop();
        if(dist[u]<=d)
            continue;
        dist[u]=d;
        for(auto x:e[u])
            pq.push({x.Y+d,x.X});
    }

    // dbg(e[0]);
    // dbg(e[n]);
    // dbg(dist);
    lli ans=INF;
    for(lli i=0;i<logN;i++)
        ans=min(ans,dist[i*n+n-1]);
    if(ans<INF)
    {
        cout<<ans%mod<<endl;
        exit(0);
    }
    dbg(dist);
    const lli offset=(logN-2)*n;
    for(lli i=offset;i<logN*n;++i)
    {
        if(dist[i]<INF)
            d2[i-offset]={logN-1,dist[i]-(1LL<<logN)/2};
    }
}

void run2(const vector<vii> &e)
{
    auto cmp=[](const pair<ii,lli> &a,const pair<ii,lli> &b){
        return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));
    };
    priority_queue < pair<ii,lli> , vector < pair<ii,lli> > , decltype(cmp) > pq(cmp);
    for(lli i=0;i<2*n;++i)
        pq.push({d2[i],i});
    dbg(d2);
    vii dist(2*n,{INF,INF});
    while(!pq.empty())
    {
        auto d=pq.top().X;
        auto u=pq.top().Y;
        // dbg(d,u);
        pq.pop();
        if(dist[u]<=d)
            continue;
        dist[u]=d;
        for(auto x:e[u])
        {
            if(x.Y>0)
                pq.push({{d.X,d.Y+1},x.X});
            else
                pq.push({{d.X+1,d.Y},x.X});
        }
    }

    dbg(dist);
    ii ans=min(dist[n-1],dist[2*n-1]);
    dbg(ans);
    cout<<(po(2,ans.X)+ans.Y)%mod<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    e.resize(logN*n);
    e2.resize(2*n);
    d2.resize(2*n,{INF,INF});
    while(m--)
    {
        cin>>u>>v;
        u--;v--;
        for(lli i=0;i<logN;i++)
        {
            e[i*n+u].pb({i*n+v,1});
            i++;
            e[i*n+v].pb({i*n+u,1});
        }
        e2[u].pb({v,1});
        e2[n+v].pb({n+u,1});
    }

    for(lli i=0;i+1<logN;i++)
    for(lli u=0;u<n;++u)
        e[i*n+u].pb({i*n+u+n,1<<i});

    for(lli u=0;u<n;++u)
    {
        e2[u].pb({u+n,-1});
        e2[u+n].pb({u,-1});
    }

    run(e);
    run2(e2);
}   aryanc403();
    return 0;
}