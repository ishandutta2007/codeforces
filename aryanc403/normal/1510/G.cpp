/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#include <vector>
#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
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
    vi a,p,b;
    vector<vi> e;
    ii deep;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dfs(lli u,lli h){
    if(h>k)
        return;
    if(deep.Y<h)
        deep={u,h};
    for(auto x:e[u])
        dfs(x, h+1);
}

void dfs2(lli u){
    a.pb(u);
    k--;
    for(auto x:e[u])
    {
        if(k==0)
            return;
        dfs2(x);
        a.pb(u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n>>k;
    e.clear();e.resize(n);
    p.clear();p.resize(n,-1);
    b.clear();
    a.clear();
    repA(i,1,n-1)
    {
        cin>>in;
        e[in-1].pb(i);
        p[i]=in-1;
    }

    deep={0,1};
    dfs(0,1);
    dbg(deep);
    k-=deep.Y;
    u=deep.X;
    lli blk=-1;
    while(u!=-1){
        dbg(u,blk);
        a.pb(u);
        dbg(u,e[u]);
        for(auto x:e[u]){
            if(k==0)
                break;
            if(x==blk)
                continue;
            dfs2(x);
            a.pb(u);
        }
        dbg(u,a);
        blk=u;
        u=p[u];
    }

    cout<<sz(a)-1<<endl;
    reverse(all(a));
    for(auto x:a)
        cout<<x+1<<" ";
    cout<<endl;

}   aryanc403();
    return 0;
}