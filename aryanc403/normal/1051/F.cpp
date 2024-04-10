/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)
 
  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
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
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

//const lli [3] ={ 999119999L,1000000007L,1000992299L};
//const lli [3] ={ 97L,101L,103L};
//const lli  = chrono::high_resolution_clock::now().time_since_epoch().count();
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(ii a , ii b) //For min priority_queue .
    {
        return ! ( a.Y <= b.Y );
    }
};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,cnt));
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const pair<ii,lli> &a,const pair<ii,lli> &b)
{
    return a.Y<b.Y;
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;
const lli MaxN = 100000L;
const lli LogN = 22L;

    lli T,n,i,j,k,in,cnt,l,r,sz,q,u,v;
    lli m;
    string s;
    vector<pair<ii,lli>> a,exc;
    vii edges[MaxN+5];
    lli d[LogN][MaxN+5];
    int p[MaxN+5][LogN],tin[MaxN+5],tout[MaxN+5];
    lli id[MaxN+5];
    vi b;
    vi :: iterator it;
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli root(lli i)
{
    if(id[i]==i)
        return i;
    return id[i]=root(id[i]);
}

void dfs(lli u,lli par=1,lli h=0)
{
    // cerr<<u<<"u par"<<par<<" "<<h<<endl;
    tin[u]=++T;
    id[u]=h;
    p[u][0]=par;
    lli i;
    repA(i,1,LogN-1)
        p[u][i]=p[p[u][i-1]][i-1];
    for(auto x:edges[u])
    {
        if(x.X==par)
            continue;
        dfs(x.X,u,h+x.Y);
    }
    tout[u]=++T;
}

bool isAnc(lli u,lli v)
// u---->v
{
    return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

lli lca(lli u,lli v)
{
    if(isAnc(u,v))
        return u;
    if(isAnc(v,u))
        return v;
    lli i;
    repD(i,LogN-1,0)
        if(!isAnc(p[u][i],v))
            u=p[u][i];
    u=p[u][0];
    return u;
}

lli solve(lli u,lli v)
{
    lli ans=id[u]+id[v]-2*id[lca(u,v)];
    lli i;
    fo(i,sz)
        ans=min(ans,d[i][u]+d[i][v]);
    return ans;
}

void djk(lli u,lli d[100005])
{
    lli i;
    repA(i,1,n)
        d[i]=INF;
    pq.push({u,0});
    while(!pq.empty())
    {
        auto x=pq.top();pq.pop();
        if(d[x.X]<=x.Y)
            continue;
        d[x.X]=x.Y;
        for(auto y:edges[x.X])
            pq.push({y.X,x.Y+y.Y});
    }
    // if(u==4)
    // {
    //     cerr<<u<<"djk : ";
    //     repA(i,1,n)
    //         cerr<<d[i]<<" ";
    //     cerr<<endl;
    // }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    fo(i,m)
    {
        cin>>u>>v>>l;
        a.pb({{u,v},l});
    }
    sort(a.begin(),a.end(),cmp);
    repA(i,1,n)
        id[i]=i;
    for(auto x:a)
    {
        if(root(x.X.X)==root(x.X.Y))
        {
            b.pb(x.X.X);
            exc.pb(x);
            continue;
        }
        id[root(x.X.X)]=root(x.X.Y);
        edges[x.X.X].pb({x.X.Y,x.Y});
        edges[x.X.Y].pb({x.X.X,x.Y});
    }
    
    dfs(1);
    
    for(auto x:exc)
    {
        edges[x.X.X].pb({x.X.Y,x.Y});
        edges[x.X.Y].pb({x.X.X,x.Y});
    }
    
    sz=(lli)b.size();
    fo(i,sz)
        djk(b[i],d[i]);
    
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<solve(u,v)<<endl;
    }
}   aryanc403();
    return 0;
}