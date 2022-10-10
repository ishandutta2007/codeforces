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

const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,c;
    lli m;
    map<lli,lli> M;
    string s;
    vi itr;
    lli d1[300005],dn[300005];
    vii a[300005];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

bool cmp(const lli &a,const lli &b)
{
    return d1[a]-dn[a]<d1[b]-dn[b];
}

void dfs(lli u,lli p,lli d[300005],lli val)
{
    d[u]=val;
    for(auto &v:a[u])
    {
        if(v.X==p)
            continue;
        dfs(v.X,u,d,val+v.Y);
    }
}

bool vis[300005];

lli fndMax(lli u)
{
    if((M.rbegin())->Y>1)
        return (M.rbegin())->X;
    for(auto &x:a[u])
    {
        if(vis[x.X])
            continue;
        if(dn[x.X]==(M.rbegin())->X)
        {
            if((lli)M.size()<=1)
                return -INF;
            map<lli,lli> :: reverse_iterator it = M.rbegin();
            it++;
            return it->X;
        }
    }
    return (M.rbegin())->X;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    itr.clear();itr.reserve(n);
    itr.pb(n);
    repA(i,1,n-1)
    {
        cin>>u>>v>>c;
        a[u].pb({v,c});
        a[v].pb({u,c});
        itr.pb(i);
    }

    dfs(1,0,d1,0);
    dfs(n,0,dn,0);
    
    sort(itr.begin(),itr.end(),cmp);
    lli ans=0;
    
    repA(i,1,n)
        add(M,dn[i]);
    
    for(auto &u:itr)
    {
        del(M,dn[u]);
        vis[u]=true;
        if(M.empty())
            continue;
        ans=max(ans,d1[u]+fndMax(u));
    }
    // cout<<ans<<endl;
    while(m--)
    {
        cin>>c;
        cout<<min(dn[1],ans+c)<<endl;
    }

}   aryanc403();
    return 0;
}