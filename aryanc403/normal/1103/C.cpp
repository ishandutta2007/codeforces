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

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v;
    lli m;
    string s;
    vi a[250005];
    lli p[250005];
    lli d[250005];
    lli bst,lf;
    vi b;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void dfs(lli u,lli pa=-1,lli dis=1)
{
    if(p[u])
        return;
    //cerr<<u<<" "<<pa<<endl;
    p[u]=pa;
    d[u]=dis;
    lli cnt=0;
    if(bst<dis)
    {
        bst=dis;
        lf=u;
    }
    for(auto x:a[u])
    {
        if(x==pa)
            continue;
        if(p[x])
            continue;
        dfs(x,u,dis+1);
        cnt++;
    }
    if(!cnt)
        b.pb(u);
}

void PATH()
{
    cout<<"PATH"<<endl;
    cout<<bst<<endl;
    u=lf;
    while(u!=-1)
    {
        cout<<u<<" ";
        u=p[u];
    }
}

lli dis(lli u,lli v)
{
    return abs(d[u]-d[v]);
}

void prt(lli u,lli v,lli x=-1)
{
    if(d[u]>d[v])
        swap(u,v);
    if(x!=-1)
    {
        cout<<2+dis(u,v)<<endl;
        cout<<x<<" ";
    }
    else
    {
        cout<<1+dis(u,v)<<endl;
    }
    //cout<<u<<"..."<<v<<endl;
    //return;
    while(v!=u)
    {
        cout<<v<<" ";
        v=p[v];
    }
    cout<<u<<endl;
}

void rep(lli v)
{
    //cerr<<v<<endl;
    //return;
    lli x=-1,y=-1;
    for(auto z:a[v])
    {
        if(z==p[v])
            continue;
        if(x==-1)
            x=z;
        else if(y==-1)
            y=z;
        else
            break;
    }
    
    if((dis(x,v)+1)%3)
        prt(x,v);
    else if((dis(y,v)+1)%3)
        prt(y,v);
    else
        prt(x,y,v);
}

void CYCLE()
{
    cout<<"CYCLES"<<endl;
    lli i=0;
    for(auto x:b)
    {
        if(i==k)
            break;
        i++;
        rep(x);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    fo(i,m)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1);
    if(bst>=n/k)
        PATH();
    else
        CYCLE();
}   aryanc403();
    return 0;
}