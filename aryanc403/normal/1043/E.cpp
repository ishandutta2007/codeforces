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
//#define endl "\n"
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
    return a.X.X<b.X.X;//&&a.Y.Y<b.Y.Y;
}

const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    string s;
    vector<pair<ii,ii> > a;
    vi :: iterator it;
    lli suma[300005],sumb[300005];
    lli ans[300005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    a.clear();a.reserve(n+1);
    a.pb({{-INF,0},{0,0}});
    repA(i,1,n)
    {
        cin>>l>>r;
        a.pb({{l-r,i},{l,r}});
    }
    
    repA(i,1,m)
    {
        cin>>l>>r;
        ans[l]-=min(a[l].Y.X+a[r].Y.Y,a[r].Y.X+a[l].Y.Y);
        ans[r]-=min(a[l].Y.X+a[r].Y.Y,a[r].Y.X+a[l].Y.Y);
    }
    
    sort(a.begin(),a.end(),cmp);
    //for(auto x:a)cout<<x.X.X<<" ";cout<<endl;
    
    repA(i,1,n)
    {
        suma[i]=suma[i-1]+a[i].Y.X;
        sumb[i]=sumb[i-1]+a[i].Y.Y;
        //cout<<suma[i]<<" "<<sumb[i]<<endl;
    }
    repA(i,1,n)
    {
        //cout<<i<<": x"<<x<<endl;
        ans[a[i].X.Y]+=sumb[n]-sumb[i]+(n-i)*a[i].Y.X;
        ans[a[i].X.Y]+=suma[i]-suma[0]+(i)*a[i].Y.Y;
        ans[a[i].X.Y]-=a[i].Y.X+a[i].Y.Y;
    }
    repA(i,1,n)
        cout<<ans[i]<<" ";
}   aryanc403();
    return 0;
}