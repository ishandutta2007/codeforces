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

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    map<string,lli> mmm;
    lli nnn=0;
    string s;
    lli a[50];
    set<lli> b;
    vi :: iterator it;
    lli dp[1LL<<20];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

lli get(const string &s)
{
    auto it=mmm.find(s);
    if(it!=mmm.end())
        return it->Y;
    nnn++;
    mmm.insert({s,nnn});
    return nnn;
}

void ins()
{
    for(auto x:b)
    for(auto y:b)
    if(x!=y)
        a[x]&=~(1LL<<y);
}
lli solve(lli);
lli solve(lli mask)
{
    lli l=mask&((1LL<<20)-1);//0...19//dp1
    lli r=mask>>20;//20...39//dp2
    if(r==0)
    {
        if(dp[l]!=-1)
            return dp[l];
        dp[l]=0;
        for(lli k=0;k<m;++k)
        {
            if(mask&(1LL<<k))
            {
                mask&=~(1LL<<k);
                dp[l]=max(solve(mask),1+solve(mask&a[k]));
                break;
            }
        }
        return dp[l];
    }
    lli cnt=0;
    lli i,j,k;
    // cout<<"test"<<r<<endl;
    for(i=0;i<=r;++i)
    {
        lli y=(i<<20);
        // cout<<y<<endl;
        lli z=(1LL<<20)-1;
        lli val=0;
        bool fl=true;
        for(j=20;j<m;++j)
        {
            if((y&(1LL<<j))==0)
                continue;
            val++;
            if((y&a[j])!=y)
            {
                // cout<<"Hello"<<endl;
                fl=false;
                break;
            }
            z&=a[j];
        }
        if(fl)
            cnt=max(cnt,val+solve(z));
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    nnn=-1;
    cin>>n>>m;
    memset(dp,-1,(1LL<<20)*sizeof(lli));
    fo(i,m)
        a[i]=(1LL<<m)-1;
    dp[0]=0;
    while(n--)
    {
        cin>>in;
        // in=n%2;
        if(in==1)
        {
            ins();
            b.clear();
        }
        else
        {
            cin>>s;
            b.insert(get(s));
        }
    }
    ins();
    cout<<solve((1LL<<m)-1)<<endl;
}   aryanc403();
    return 0;
}