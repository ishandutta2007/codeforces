/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

// https://codeforces.com/contest/1107/submission/50910402
// Tags - maximum subarray sum

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

const lli INF = 1e9;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || a.X==b.X && a.Y == b.Y);   }};

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
const lli maxN = 1000000L;

lli max(long long int x,int y)
{
    if(x>y)
        return x;
    return y;
}

typedef struct _node{
    lli lmax,rmax,sum,ans;
    _node(lli n=0) : lmax(max(0LL,n)),rmax(max(0LL,n)),sum(n),ans(max(0LL,n)){};
}node;

ostream& operator << (ostream& out, const node &x) {
    return out<<"[ lmax : "<<x.lmax<<","<<" rmax : "<<x.rmax<<","<<" sum "<<x.sum<<","<<" ans "<<x.ans<<" ] ";
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,d,c,ans;
    lli m;
    string s;
    vi a,ed[maxN+5];
    node final[8*maxN+5];
    lli tin[maxN+5],tout[maxN+5];

node merge(node a,node b)
{
    node n;
    n.lmax=max(a.lmax,a.sum+b.lmax);
    n.rmax=max(a.rmax+b.sum,b.rmax);
    n.sum=a.sum+b.sum;
    n.ans=max(a.ans,b.ans);
    n.ans=max(n.ans,a.rmax+b.lmax);
    return n;
}

void add(lli id,lli l,lli r,lli i,lli c)
{
    if(l>r||i<l||r<i)
        return;
    if(l==r)
    {
        final[id]=node(c);
        return;
    }
    lli m=(l+r)/2;
    add(2*id,l,m,i,c);
    add(2*id+1,m+1,r,i,c);
    final[id]=merge(final[2*id],final[2*id+1]);
}

node query(lli id,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||R<l)
        return node(0);
    if(L<=l&&r<=R)
        return final[id];
    lli m=(l+r)/2;
    return merge(query(2*id,l,m,L,R),query(2*id+1,m+1,r,L,R));
}

lli query(lli l,lli r)
{
    return query(1,1,T,l,r).ans;
}

void dfs(lli u)
{
    tin[u]=++T;
    for(auto x:ed[u])
        dfs(x);
    tout[u]=++T;
    dbg(u,tin[u],tout[u]);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;
    a.clear();a.reserve(n+1);
    a.pb(INF);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    a.pb(INF);
    stack<ii> s;
    s.push({INF,n+1});
    repD(i,n,1)
    {
        while(s.top().X<=a[i])
            s.pop();
        ed[s.top().Y].pb(i);
        dbg("edge",s.top().Y,i);
        s.push({a[i],i});
    }
    dfs(n+1);
    repA(i,1,k-1)
    {
        add(1,1,T,tin[i],1);
        add(1,1,T,tout[i],-1);
    }

    repA(i,k,n)
    {
        add(1,1,T,tin[i],1);
        add(1,1,T,tout[i],-1);

        cout<<query(1,T)<<" ";

        add(1,1,T,tin[i-k+1],0);
        add(1,1,T,tout[i-k+1],0);
    }

}   aryanc403();
    return 0;
}