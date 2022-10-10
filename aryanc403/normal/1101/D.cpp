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

    lli T,n,i,j,k,in,cnt,l,r,ans;
    lli m;
    string s;
    vi a;
    vi fac[200005],ed[200005];
    lli fl[200005];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void pre(lli n)
{
    lli i,j;
    repA(i,1,n)
        fl[i]=1;
    repA(i,2,n)
    {
        if(fac[i].empty())
        {
            for(j=i;j<=n;j+=i)
                fl[j]*=i;
        }
        for(j=i;j<=n;j+=i)
            fac[j].pb(i);
    }
}

void dfs(lli u,lli p,map<lli,lli> &m)
{
    if(a[u]!=1)
    {
        ans=max(ans,(lli)1);
    }
    for(auto x:fac[a[u]])
        m.insert({x,1});
    map<lli,lli> v;
    for(auto x:ed[u])
    {
        if(x==p)
            continue;
        v.clear();
        dfs(x,u,v);
        for(auto g:fac[a[u]])
        {
            auto it=v.find(g);
            if(it!=v.end())
            {
                auto jt=m.find(g);
                if(jt==m.end())
                {
                    ans=max(ans,it->Y+1);
                    m.insert({g,it->Y+1});
                }
                else
                {
                    ans=max(ans,jt->Y+it->Y);
                    jt->Y=max(jt->Y,it->Y+1);
                }
            }
        }
    }
        //cerr<<u<<" map - ";
        //for(auto x:m)
           // cerr<<x.X<<"-"<<x.Y<<endl;
            //cerr<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
pre(200000L);
{

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(fl[in]);
    }
    
    fo(i,n-1)
    {
        cin>>l>>r;
        ed[l].pb(r);
        ed[r].pb(l);
    }
    map<lli,lli> tmp;
    dfs(1,-1,tmp);
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}