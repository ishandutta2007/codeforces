/************************************************************************************************************************************************************************************
  *                                                                                                                                                                                  *
   *                                                                                                                                                                                  *
    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
                 *                                                                                                                                                                                  *
                  *                                                                                                                                                                                  *
                   ************************************************************************************************************************************************************************************/
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

void add( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,1));
    else                    jt->Y++;
}

void del( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y==1)            m.erase(jt);
    else                    jt->Y--;
}

bool CMp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l,r,x,y;
    vi a[300005],b[300005],c[300005];
    vi :: iterator it;
    string s;
    lli disc[300005],low[300005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .
lli cmp[300005];

void dfs(lli u,lli par)
{
    T++;
    disc[u]=low[u]=T;
    for(auto &x:a[u])
    {
        if(x==par)
            continue;
        if(disc[x])
        {
            low[u]=min(low[u],disc[x]);
            continue;
        }
        dfs(x,u);
        low[u]=min(low[u],low[x]);
    }
    if(low[u]>disc[par])
    {
        b[u].pb(par);
        b[par].pb(u);
    }
    else
    {
        cmp[u]=par;
    }
}
bool vis[300005];
lli dia(lli u,lli p)
{
    vis[u]=true;
    vi a;
    for(auto &x:c[u])
    {
        if(x==p||x==u)
            continue;
        if(vis[x])
            while(1);
        a.pb(-dia(x,u));
    }
    a.pb(0);a.pb(0);
    sort(a.begin(),a.end());
    cnt=max(cnt,-a[0]-a[1]);
    return -a[0]+1;
}

lli root(lli u)
{
    if(cmp[u]==u)
        return u;
    return root(cmp[u]);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cin>>T;while(T--)
{

    cin>>n>>m;
    fo(i,m)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    repA(i,1,n)
        cmp[i]=i;
    disc[0]=INF;
    dfs(1,1);
    repA(i,1,n)
    {
        for(auto &x:b[i])
        {
            c[root(i)].pb(root(x));
        }
    }

    dia(root(1),0);
    cout<<cnt;
}   aryanc403();
    return 0;
}