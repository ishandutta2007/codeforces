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

    lli T,n,i,j,k,in,cnt,l,r,v,d,x,y;
    lli m;
    string s;
    vi a[300005];
    map<lli,lli> val[300005];
    lli h[300005],ans[300005];
    lli hmax;
    vi :: iterator it;
    lli final[1200005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p=-1,lli di=1)
{
    h[u]=di;
    hmax=max(hmax,di);
    for(auto x:a[u])
    {
        if(x==p)
           continue;
          dfs(x,u,di+1);
    }
}

void upd(lli root,lli l,lli r,lli L,lli R,lli val)
{
    if(l>r||R<l||L>r)
        return;
    if(L<=l&&r<=R)
    {
        final[root]+=val;
        return;
    }
    lli m=l+(r-l)/2;
    upd(2*root,l,m,L,R,val);
    upd(2*root+1,m+1,r,L,R,val);
}

lli query(lli root,lli l,lli r,lli pos)
{
    //cerr<<"quercall "<<root<<" "<<l<<" "<<r<<" "<<pos<<endl;
    if(l>r||l>pos||r<pos)
        return 0;
    if(l==r)
    {
        if(l==pos)
        return final[root];
        return 0;
    }
    lli m=l+(r-l)/2;
    lli ans=final[root];
    ans+=query(2*root,l,m,pos);
    ans+=query(2*root+1,m+1,r,pos);
    return ans;
}

void dfs2(lli u,lli p=-1)
{
    for(auto x:val[u])
    {
        upd(1,1,hmax,h[u],x.X,x.Y);
        // cerr<<"add "<<h[u]<<" to "<<x.X<<" "<<x.Y<<endl;
    }
    ans[u]=query(1,1,hmax,h[u]);
    // cerr<<"query "<<h[u]<<" "<<query(1,1,hmax,h[u])<<endl;
    for(auto x:a[u])
    {
        if(x==p)
            continue;
        dfs2(x,u);
    }
    for(auto x:val[u])
    {
        upd(1,1,hmax,h[u],x.X,-x.Y);
        // cerr<<"add "<<h[u]<<" to "<<x.X<<" "<<-x.Y<<endl;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n;
    // a.clear();a.reserve(n);
    fo(i,n-1)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    cin>>m;
    while(m--)
    {
        cin>>v>>d>>x;
        //cerr<<v<<" "<<d<<" "<<x<<endl;
        add(val[v],min(h[v]+d,hmax),x);
    }
    dfs2(1);
    repA(i,1,n)
        cout<<ans[i]<<" ";
}   aryanc403();
    return 0;
}