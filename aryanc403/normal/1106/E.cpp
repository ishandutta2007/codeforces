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

bool cmp(const pair<ii,ii> &a,const pair<ii,ii> &b)
{
    return a.Y.Y>b.Y.Y||(a.Y.Y==b.Y.Y&&a.Y.X>b.Y.X);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m,s,t,d,w;
    vector<pair<ii,ii>> a;
    lli dp[100005][205];
    int dpd[100005][205];
    int p[100005];
    set<lli> ss;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

pair<lli,int> solve(lli n,lli d)
{
    if(d<0)
        return {INF,INF};
    if(n==0)
        return {0,0};
    if(dpd[n][d]!=-1)
        return {dp[n][d],dpd[n][d]};
    ii v=solve(n-1,d-1),u=solve(n-1,d);
    
    // if(v.Y<n&&p[n]!=-1)
    // {
    //     v.X+=a[p[n]].Y.Y;
    //     v.Y=a[p[n]].Y.X;
    // }
    
    if(u.Y<n&&p[n]!=-1)
    {
        u.X+=a[p[n]].Y.Y;
        u.Y=a[p[n]].Y.X;
    }
    
    if(v.X<u.X)
        tie(dp[n][d],dpd[n][d])=v;
    else
        tie(dp[n][d],dpd[n][d])=u;
    return {dp[n][d],dpd[n][d]};
}

void setP()
{
    sort(a.begin(),a.end(),cmp);
    lli i;
    repA(i,1,n)
        ss.insert(i);
    ss.insert(INF);
    fo(i,k)
    {
        auto it=ss.lower_bound(a[i].X.X);
        //cerr<<a[i].X.X<<" "<<a[i].X.Y<<" "<<a[i].Y.X<<" "<<a[i].Y.Y<<endl;
        while(*it<=a[i].X.Y)
        {
            p[*it]=i;
            // cout<<*it<<"-"<<a[i].Y.Y<<endl;
            ss.erase(it++);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    memset(dp,-1,100005*205*sizeof(lli));
    memset(dpd,-1,100005*205*sizeof(int));
    memset(p,-1,100005*sizeof(int));
    
    cin>>n>>m>>k;
    a.clear();a.reserve(k);
    
    fo(i,k)
    {
        cin>>s>>t>>d>>w;
        a.pb({{s,t},{d,w}});
    }
    setP();
    
    for(d=m;d>=0;d--)
        dp[n+1][d]=0;
    
    for(i=n;i>0;i--)
    {
        // cout<<p[i]<<endl;
        for(d=m;d>=0;d--)
        {
            if(p[i]!=-1)
                dp[i][d]=dp[a[p[i]].Y.X+1][d]+a[p[i]].Y.Y;
            else
                dp[i][d]=dp[i+1][d];
            
            if(d)
                dp[i][d]=min(dp[i][d],dp[i+1][d-1]);
            // cout<<dp[i][d]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[1][m]<<endl;
}   aryanc403();
    return 0;
}