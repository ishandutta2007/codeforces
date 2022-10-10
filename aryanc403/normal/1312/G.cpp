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

struct node{
    map<char,node*> nxt;
    int n;
    int fl,l,r;
    node(int _n):n(_n),fl(-1){};
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<node*> a;
    vi ans,f;
    vi b; 
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

// void dfsdbg(node *nd,string s){
//     if(nd==NULL)
//         return;
//     dbg(nd->n,s);
//     for(auto x:nd->nxt)
//         dfsdbg(x.Y,s+x.X);
// }

void dfs(node *nd){
    if(nd==NULL)
        return;
    nd->l=T+1;
    if(nd->fl!=-1)
        nd->fl=++T;
    for(auto x:nd->nxt)
        dfs(x.Y);
    nd->r=T;
}

void update(lli id,lli l,lli r,lli L,lli R,lli cst){
    if(r<L||R<l)
        return;
    if(L<=l&&r<=R){
        f[id]=min(f[id],cst+l-L);
        return;
    }
    lli m=(l+r)/2;
    update(2*id,l,m,L,R,cst);
    update(2*id+1,m+1,r,L,R,cst);
}

void update(lli l,lli r,lli cst){
    if(r<l)
        return;
    dbg("update",l,r,cst);
    update(1,1,k,l,r,cst);
}

lli query(lli id,lli l,lli r,lli pos){
    if(r<pos||l>pos)
        assert(false);
    if(l==r)
        return f[id];
    lli m=(l+r)/2;
    if(m>=pos)
        return min(f[id]+pos-l,query(2*id,l,m,pos));
    return min(f[id]+pos-l,query(2*id+1,m+1,r,pos));
}

lli get(lli id){
    return query(1,1,k,id);
}

void dfsSolve(node *nd,lli cst){
    if(nd==NULL)
        return;
    if(nd->fl!=-1)
    {
        cst=min(cst,get(nd->fl));
        ans[nd->n]=cst;
        dbg(nd->n,cst);
    }
    else
    {
        dbg(nd->n,cst);
    }
    update(nd->l,nd->r,cst+1);
    for(auto x:nd->nxt)
        dfsSolve(x.Y,cst+1);
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
    a.pb(new node(0));
    repA(i,1,n){
        char c;
        int p;
        cin>>p>>c;
        a.pb(a[p]->nxt[c]=new node((int)i));
    }

    // dfsdbg(a[0],"");

    cin>>k;
    ans.resize(n+1);

    repA(i,1,k){
        cin>>in;
        b.pb(in);
        a[in]->fl=1;
    }
    
    f.resize(4*k+4,INF);
    dfs(a[0]);
    dfsSolve(a[0],0);

    for(auto x:b)
        cout<<ans[x]<<endl;

    // sort(all(b),[&](const ii &x,const ii &y){
    //     return x.Y<y.Y;
    // });

    // repA(i,1,k)
    //     cout<<ans[b[i].X]<<endl;
}   aryanc403();
    return 0;
}