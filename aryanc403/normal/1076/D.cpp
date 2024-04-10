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
typedef pair<lli, ii> iii;//ed,wt,no.
typedef pair<ii, ii> iiii;//ed,wt,no.
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
    bool operator()(iiii a , iiii b) //For min priority_queue .
    {
        return ! ( a.Y.X<=b.Y.X );
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

bool cmp(const iiii &a,const iiii &b)
{
    return a.Y.X<b.Y.X;
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,x,y,w;
    lli m;
    string s;
    vector<iii> a[300005];//ed,wt,no.
    vii b[300005];
    vi :: iterator it;
    lli d[300005];
    priority_queue < iiii , vector < iiii > , CMP > pq;// min priority_queue .
    set<lli> rmv,lef;
    // ver,par,dis,idx

bool dfs(lli u,lli pe)
{
    lli sz=(lli)b[u].size();
    for(auto x:b[u])
        sz-=dfs(x.X,x.Y);
    if(sz==0&&cnt>k)
    {
        cnt--;
        lef.erase(lef.find(pe));
        return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    // a.clear();a.reserve(n);
    repA(i,1,m)
    {
        cin>>x>>y>>w;
        a[x].pb({y,{w,i}});
        a[y].pb({x,{w,i}});
    }
    repA(i,1,n)
        d[i]=INF;
    pq.push({{1,-1},{0,0}});
    while(!pq.empty())
    {
        iiii u=pq.top();pq.pop();
        if(u.Y.X>=d[u.X.X])
        {
            rmv.insert(u.Y.Y);
            continue;
        }
        d[u.X.X]=u.Y.X;
        if(u.X.Y!=-1)
        {
            lef.insert(u.Y.Y);
            b[u.X.Y].pb({u.X.X,u.Y.Y});
        }
        for(auto x:a[u.X.X])
            pq.push({{x.X,u.X.X},{u.Y.X+x.Y.X,x.Y.Y}});
    }
    cnt=(lli)lef.size();
    if(cnt>k)
    {
        dfs(1,-1);
    }
    cout<<(lli)lef.size()<<endl;
    for(auto x:lef)
    {
        cout<<x<<" ";        
    }

}   aryanc403();
    return 0;
}