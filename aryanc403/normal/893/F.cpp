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
const lli maxN = 100000L;

struct node{
    lli v;
    struct node *l,*r;
};

node* NODE(lli x=INF)
{
    node *nd=(node*)malloc(sizeof(node));
    nd->l=nd->r=NULL;
    nd->v=x;
    return nd;
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,e[maxN+5];
    node *f[maxN+5];
    lli h[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

node* add(lli l,lli r,lli U,lli x)
{
    if(l>r||r<U||U<l)
        return NULL;
    node *nd=NODE(x);
    if(l==r)
        return nd;
    lli m=(l+r)/2;
    nd->l=add(l,m,U,x);
    nd->r=add(m+1,r,U,x);
    return nd;
}

node *merge(node* a,node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    node* nd=NODE(min(a->v,b->v));
    nd->l=merge(a->l,b->l);
    nd->r=merge(a->r,b->r);
    return nd;
}

node *dfs(lli u,lli p,lli hh)
{
    h[u]=hh;
    // return NULL;
    f[u]=add(1,n,hh,a[u]);
    // return NULL;
    for(auto x:e[u])
    {
        if(x==p)
            continue;
        f[u]=merge(f[u],dfs(x,u,hh+1));
    }
    dbg(u,p,a[u],hh);
    return f[u];
}

lli query(node* id,lli l,lli r,lli L,lli R)
{
    if(id==NULL||r<L||R<l)
        return INF;
    if(L<=l&&r<=R)
        return id->v;
    lli m=(l+r)/2;
    return min(query(id->l,l,m,L,R),query(id->r,m+1,r,L,R));
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>r;
    a.clear();a.reserve(n+1);
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
    
    // return 0;
    dfs(r,-1,1);
    // return 0;
    lli ans=0;
    cin>>m;
    while(m--)
    {
        cin>>u>>v;
        u=(u+ans)%n+1;
        v=(v+ans)%n;
        ans=query(f[u],1,n,h[u],h[u]+v);
        cout<<ans<<endl;
        // return 0;
    }

}   aryanc403();
    return 0;
}