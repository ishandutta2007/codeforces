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
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return ! ( a <= b );
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

bool cmp(const pair <ii,ii> &a,const pair <ii,ii> &b)
{
    return a.Y.X<b.Y.X;
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,cnt,l,r,w;
    lli m;
    string s;
    lli mst[200005];
    lli id[200005];
    vii a[200005];
    vector < pair <ii,ii> > ver;
    lli ans[200005];
    vi :: iterator it;
    lli in[200005],out[200005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .
    ii par[200005][36];
    bool vis[200005];

lli root(lli n)
{
    if(id[n]==n)
        return n;
    return id[n]=root(id[n]);
}

void dfs(lli u,lli p=1,lli w=-INF)
{
    lli i;
    par[u][0]={p,w};
    in[u]=++T;
    repA(i,1,35)
        par[u][i]={par[par[u][i-1].X][i-1].X,max(par[u][i-1].Y,par[par[u][i-1].X][i-1].Y)};
    for(auto &x:a[u])
    {
        if(x.X==p)
            continue;
        dfs(x.X,u,x.Y);
    }
    out[u]=++T;
}

bool isAnc(lli u,lli v)//u====>v
{
    return in[u]<=in[v]&&out[v]<=out[u];
}

lli fndMax(lli l,lli v)
{
    // cout<<l<<"l v"<<v<<endl;
    lli w=0;
    lli i=0;
    repD(i,35,0)
    {
        if(l==v)
            break;
        if(isAnc(l,par[v][i].X))
        {
            w=max(w,par[v][i].Y);
            v=par[v][i].X;
        }
    }
    return w;
}

lli fnd(lli u,lli v)
{
    if(isAnc(u,v))
    {
        return fndMax(u,v);
    }
    
    if(isAnc(v,u))
    {
        return fndMax(v,u);
    }
    // cout<<"case 3"<<endl;
    lli l=u;
    lli i=0;
    repD(i,35,0)
    {
        if(!isAnc(par[l][i].X,v))
            l=par[l][i].X;
    }
    l=par[l][0].X;
    return max(fndMax(l,u),fndMax(l,v));
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    repA(i,1,n)
        id[i]=i;
    fo(i,m)
    {
        cin>>l>>r>>w;
        ver.pb({{l,r},{w,i}});
    }
    sort(ver.begin(),ver.end(),cmp);
    w=0;
    for(auto &x:ver)
    {
        if(root(x.X.X)!=root(x.X.Y))
        {
            w+=x.Y.X;
            id[root(x.X.X)]=root(x.X.Y);
            a[x.X.X].pb({x.X.Y,x.Y.X});
            a[x.X.Y].pb({x.X.X,x.Y.X});
            vis[x.Y.Y]=true;
        }
    }
    
    dfs(1);
    
    // repA(i,1,n)
    // {
    //     repA(j,1,n)
    //         cout<<fnd(i,j)<<" ";
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    // cout<<fnd(4,5)<<endl<<endl;
    
    for(auto &x:ver)
    {
        if(vis[x.Y.Y])
            ans[x.Y.Y]=w;
        else
            ans[x.Y.Y]=w+x.Y.X-fnd(x.X.X,x.X.Y);
    }
    
    fo(i,m)
        cout<<ans[i]<<endl;
    
}   aryanc403();
    return 0;
}