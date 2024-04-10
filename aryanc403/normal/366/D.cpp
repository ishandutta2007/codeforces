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

bool cmp2(const pair<lli,ii> &a,const pair<lli,ii> &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y.X<b.Y.X)||(a.X==b.X&&a.Y.X==b.Y.X&&a.Y.Y<b.Y.Y);
}

const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v;
    lli m;
    string s;
    vector<pair<lli,ii>> a[1005];
    vi :: iterator it;
    set<lli> rng;
    bool vis[1005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

bool dfs(lli u,lli l,lli r)
{
    if(vis[u])
        return false;
    if(u==1)
        return true;
    vis[u]=true;
    
    for(auto x:a[u])
    {
        if(x.Y.X<=l&&r<=x.Y.Y&&dfs(x.X,l,r))
            return true;
    }
    return false;
    
    // auto it=a[u].begin();
    // while(it!=a[u].end())
    // {
    //     lli x=it->X;
    //     lli pvr=l-1;
    //     while(it!=a[u].end()&&it->X==x)
    //     {
    //         if((it->Y).X<=pvr+1)
    //             pvr=max(pvr,(it->Y).Y);
    //         it++;
    //     }
    //     if(pvr>=r&&dfs(x,l,r))
    //         return true;
    // }
    // return false;
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
        cin>>l>>r>>u>>v;
        rng.insert(u);
        a[r].pb({l,{u,v}});
        a[l].pb({r,{u,v}});
    }
    
    repA(i,1,n)
        if(!a[i].empty())
            sort(a[i].begin(),a[i].end(),cmp2);
    
    lli ans=0;
    for(auto x:rng)
    {
        lli l=x-1,r=INF;
        while(r-l>1)//[l,r)
        {
            memset(vis,false,1005*sizeof(bool));
            lli m=(l+r)/2;
            if(dfs(n,x,m))
                l=m;
            else
                r=m;
        }
        ans=max(ans,l-x+1);
    }
    if(ans)
        cout<<ans<<endl;
    else
        cout<<"Nice work, Dima!"<<endl;
}   aryanc403();
    return 0;
}