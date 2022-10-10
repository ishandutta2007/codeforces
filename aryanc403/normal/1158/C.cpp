/* in the name of Anton */

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
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<vi> e;
    vi a,c,ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .
    queue<lli> pq;
    vi fmn,lazy;

void push(lli id,lli d)
{
    fmn[id]+=d;
    lazy[id]+=d;
    dbg(id,fmn[id],lazy[id],d);
}

void add(lli id,lli l,lli r,lli L,lli R,lli d)
{
    if(r<L||R<l)
        return;

    if(L<=l&&r<=R)
    {
        push(id,d);
        if(fmn[id]>0)
            return;
        d=0;
    }

    if(l==r)
    {
        if(fmn[id]>0)
            return;
        pq.push(l);
        fmn[id]=INF;
        return;
    }

    push(2*id,lazy[id]);
    push(2*id+1,lazy[id]);
    lazy[id]=0;    

    lli m=(l+r)/2;
    add(2*id,l,m,L,R,d);
    add(2*id+1,m+1,r,L,R,d);
    fmn[id]=min(fmn[2*id],fmn[2*id+1]);
}

void add(lli l,lli r,lli d)
{
    dbg(l,r,d);
    add(1,1,n,l,r,d);
}

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        fmn[id]=c[l];
        return;
    }
    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    fmn[id]=min(fmn[2*id],fmn[2*id+1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    while(!pq.empty())
        pq.pop();

    cin>>n;
    fmn.clear();fmn.resize(4*n);
    lazy.clear();lazy.resize(4*n);
    e.clear();e.resize(n+2);
    c.clear();c.resize(n+2);
    ans.clear();ans.resize(n);
    a.clear();a.pb(0);
    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
        if(in==-1)
            continue;
        c[i]++;c[in]--;
        if(in==n+1)
        {
            c[i]--;
            c[i+1]++;
        }
        else
            e[in].pb(i);
    }

    repA(i,1,n)
    {
        c[i]+=c[i-1];
        if(c[i]==0)
            pq.push(i);
    }

    dbg(c);

    build(1,1,n);
    bool fl=false;
    for(lli cur=n;cur;cur--)
    {
        if(pq.empty())
        {
            cout<<-1<<endl;
            fl=true;
            break;
        }
        auto u=pq.front();pq.pop();
        dbg(u);
        ans[u-1]=cur;
        add(u+1,a[u]-1,-1);
        dbg(u,a[u]-1,e[u])
        for(auto x:e[u])
            add(x,x,-1);
    }

    if(fl)
        continue;

    for(auto x:ans)
        cout<<x<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}