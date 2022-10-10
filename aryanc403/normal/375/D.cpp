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
typedef int lli;
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

const lli R = 323L;

bool cmp(const pair<ii,ii> &a,const pair<ii,ii> &b)
{
    return a.X.X<b.X.X;
}

const lli mod = 1000000007L;
const lli maxN = 100000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m[maxN+5];
    string s;
    vi a,e[maxN+5];
    lli tin[maxN+5],tout[maxN+5],ans[maxN+5],par[maxN+5];
    vi b;
    vector<pair<ii,ii>> qur;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p)
{
    dbg(u);
    par[u]=p;
    tin[u]=(lli)b.size();
    b.pb(a[u]);
    for(auto x:e[u])
    {
        if(x==p)
            continue;
        dfs(x,u);
    }
    tout[u]=-1+(lli)b.size();
}

lli bit[maxN+5];

lli sum(lli x)
{
    lli cnt=0;
    while(x>0)
    {
        cnt+=bit[x];
        x-=(x&(-x));
    }
    return cnt;
}

void add(lli x,lli u)
{
    while(x<=maxN)
    {
        bit[x]+=u;
        x+=(x&(-x));
    }
}

lli get(lli x)
{
    return sum(maxN)-sum(x-1);
}

void add(lli x)
{
    if(m[x])
        add(m[x],-1);
    m[x]++;
    add(m[x],1);
}

void del(lli x)
{
    add(m[x],-1);
    m[x]--;
    if(m[x]!=0)
        add(m[x],1);
}

void solve()
{
    sort(qur.begin(),qur.end(),cmp);
    l=r=1;
    dbg(b);
    add(b[1]);
    for(auto x:qur)
    {
        while(r<x.X.Y)
            add(b[++r]);
        while(r>x.X.Y)
            del(b[r--]);
        while(l>x.X.X)
            add(b[--l]);
        while(l<x.X.X)
            del(b[l++]);
        dbg(x,m);
        ans[x.Y.Y]=get(x.Y.X);
    }
}

map<lli,lli> M;

void dfs2(lli u,lli p)
{
    M[a[u]]++;
    for(auto x:e[u])
        if(x!=p)
            dfs2(x,u);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli m;
    cin>>n>>m;
    a.clear();a.reserve(n);
    // R=sqrt(n);R+=2;
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    fo(i,n-1)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }

    b.pb(0);
    dfs(1,0);

    repA(i,1,m)
    {
        cin>>v>>k;

        l=tin[v];r=tout[v];
        if(l/R!=r/R)
            qur.pb({{l,r},{k,i}});
        else
        {
            M.clear();
            dfs2(v,par[v]);
            for(auto x:M)
                ans[i]+=(x.Y>=k);
        }
    }

    solve();

    repA(i,1,m)
        cout<<ans[i]<<endl;

}   aryanc403();
    return 0;
}