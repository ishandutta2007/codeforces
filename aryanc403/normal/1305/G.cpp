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

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
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
const lli L = 18L;
const lli M = (1LL<<L)-1;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b;
    int mx[M+5];
    bitset<M+1> vis;
    int id[M+1];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int getRoot(int n)
{
    if(id[n]==n)
        return n;
    return id[n]=getRoot(id[n]);
}

bool join(int u,int v)
{
    u=getRoot(u);
    v=getRoot(v);
    id[u]=v;
    return u!=v;
}

lli mxcomp(const vi &b)
{
    for(int i=1;i<=M;++i)
        for(int j=0;j<L;++j)
            if(i&(1<<j))
                mx[i]=max(mx[i],mx[i^(1<<j)]);
    lli ans=0;
    for(auto x:b)
        ans+=mx[M^x];
    return ans;
}

lli solve()
{
    lli ans=0;
    for(int k=M;k>=0;--k)
        for(int j=k;j>k-j;j=(j-1)&k)
            if(vis[j]&&vis[k-j]&&join(k-j,j))
                ans+=k;
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;

    iota(id,id+M+1,0);
    dbg(id[0],id[5],id[10],id[M]);
    lli ans=0;
    vis[0]=1;
    fo(i,n)
    {
        cin>>in;
        if(vis[in])
            b.pb(in);
        else
        {
            vis[in]=1;
            mx[in]=in;
            ans-=in;
        }
    }

    ans+=mxcomp(b);
    ans+=solve();
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}