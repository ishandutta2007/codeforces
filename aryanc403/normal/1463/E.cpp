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
    vi a,id;
    vector<vi> b,e;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli find(lli u)
{
    if(id[u]==u)
        return u;
    return id[u]=find(id[u]);
}

vi ans;

void prt(lli u)
{
    // cout<<u<<" ";
    ans.pb(u);
    while(!b[u].empty())
    {
        u=b[u][0];
        ans.pb(u);
        // cout<<u<<" ";
    }
}

vi get()
{
    dbg(e);
    vi ord,deg(n+1);
    queue<lli> q;
    for(int i=0;i<=n;++i)
    {
        for(auto x:e[i])
            deg[x]++;
    }

    for(int i=0;i<=n;++i)
    {
        if(deg[i]==0)
            q.push(i);
    }
    dbg(deg);
    while(!q.empty())
    {
        const int u=q.front();q.pop();
        ord.pb(u);
        for(auto x:e[u])
        {
            deg[x]--;
            if(deg[x]==0)
                q.push(x);
        }
    }
    return ord;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    b.resize(n+1);
    id.resize(n+1);
    e.resize(n+1);
    iota(all(id),0);
    dbg(id);
    a.pb(-1);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    vii pairs;
    fo(i,k)
    {
        cin>>u>>v;
        if(find(v)!=v)
        {
            cout<<0<<endl;
            return 0;
        }
        if(!b[u].empty())
        {
            cout<<0<<endl;
            return 0;
        }
        if(find(v)==find(u))
        {
            cout<<0<<endl;
            return 0;
        }
        b[u].pb(v);
        id[v]=u;
    }

    repA(i,1,n)
    {
        const lli u=find(i),v=find(a[i]);
        if(u==v)
            continue;
        e[v].pb(u);
        dbg(u,v);
    }

    auto topo=get();
    dbg(topo);
    if(sz(topo)<=n)
    {
        cout<<0<<endl;
        return 0;
    }
    for(auto x:topo)
    {
        if(x==0)
            continue;
        if(find(x)!=x)
            continue;
        prt(x);
    }

    dbg(ans);
    vi pos(n+1);
    for(int i=0;i<n;++i)
        pos[ans[i]]=i+1;
    for(int i=1;i<=n;++i)
    {
        if(pos[i]<pos[a[i]])
        {
            cout<<0<<endl;
            return 0;
        }
    }
    for(auto x:ans)
        cout<<x<<" ";

}   aryanc403();
    return 0;
}