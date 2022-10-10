/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

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
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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
const lli maxV = 2000000L;
const lli maxN = 100000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,q;
    lli m;
    string s;
    vi a;
    vi f[maxV+5],e[maxN+5];
    lli ans[maxN+5];
    // priority_queue < ii , vector < ii > , CMP > pq[maxN+5];// min priority_queue .
    vii pq[maxV+5];

void pre(lli n)
{
    for(lli i=2;i<=n;++i)
    {
        if(!f[i].empty())
            continue;
        for(lli j=i;j<=n;j+=i)
            f[j].pb(i);
    }
}

void dfs(lli u=1,lli p=-1,lli h=0)
{
    lli &mx=ans[u],hh=-1;
    mx=-1;
    dbg(u,a[u],f[a[u]]);
    for(auto x:f[a[u]])
    {
        // dbg(x,find(pq[x]));
        if(!pq[x].empty())
        {
            if(pq[x].back().Y>hh)
                tie(mx,hh)=pq[x].back();
        }
        pq[x].pb({u,h});
    }
    dbg(mx);
    // return;
    for(auto x:e[u])
    {
        if(x==p)
            continue;
        dfs(x,u,h+1);
    }
    for(auto x:f[a[u]])
        pq[x].pop_back();
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    pre(maxV);
    cin>>n>>q;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    fo(i,n-1)
    {
        cin>>l>>r;
        e[l].pb(r);
        e[r].pb(l);
    }

    dfs();
    dbg("Hello");
    // return 0;

    while(q--)
    {
        cin>>in>>u;
        if(in==1)
            cout<<ans[u]<<endl;
        else
        {
            cin>>in;
            a[u]=in;
            dfs();
        }
    }

}   aryanc403();
    return 0;
}