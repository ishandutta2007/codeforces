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

void add( map<lli,lli> &m, lli x,lli y=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,y));
    else                    jt->Y+=y;
}

void del( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y==1)            m.erase(jt);
    else                    jt->Y--;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l,x,y;
    vi a[1000005];
    vi :: iterator it;
    string s;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .
bool vis[1000005];

lli dfs(lli u)//
{
    lli b,c;
    vis[u]=true;
    b=c=0;
    for(auto &v:a[u])
    {
        if(vis[v])
            continue;
        c=dfs(v);
        if(b+c>k)
        {
            cnt++;
            b=min(b,c);
        }
        else
        {
            b=max(b,c);
        }
    }
    // cout<<u<<"return "<<b+1<<endl;
    return b+1;
}

lli dfs(lli u,lli p)
{
    // cout<<u<<" "<<p<<endl;
    map<lli,lli> m;
    map<lli,lli> :: iterator it,jt;
    for(auto &v:a[u])
    {
        if(v==p)
            continue;
        add(m,dfs(v,u));
    }
    
    if(m.empty())
        return 1;
    
    it=m.begin();
    jt=m.begin();
    jt++;
    for(;jt!=m.end();++it,++jt)
    {
        if(it->X+jt->X<=k)
            continue;
        else
            break;
    }
    
    lli val=0;
    ii cur = *it;
    
    it++;
    while(it!=m.end())
    {
        cnt+=it->Y;
        it++;
    }
    
    if(2*(cur.X)>k)
        cnt+=cur.Y-1;
    
    if(cur.X>=k)
    {
        cnt++;
        val=0;
    }
    else if(cur.X)
        val=cur.X+1;
    // cout<<u<<" "<<val<<endl;
    return val;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cin>>T;while(T--)
{

    cin>>n>>k;
    fo(i,n-1)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    repA(i,1,n)
    {
        if(((lli)a[i].size())>1)
            break;
    }
    cnt=0;
    cnt+=(dfs(i,0)>0);
    cout<<cnt<<endl;
}   aryanc403();
    return 0;
}