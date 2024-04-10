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
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 998244353L;

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class cmp
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return a > b;
    }
};

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

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


    lli T,n,i,m,j,k,in,cnt,l;
    vi a;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .
    lli fac[1005],inv[1005],dp[1005];
    
lli po(lli a,lli p)
{
    if(p==0)
        return 1;
    lli c=po(a,p/2);
    c=(c*c)%mod;
    if(p%2)
        c=(c*a)%mod;
    return c;
}
    
void pre()
{
    fac[0]=1;
    for(lli i=1;i<=1000;++i)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    
    inv[1000]=po(fac[1000],mod-2);
    
    for(lli i=999;i>=0;--i)
    {
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();

    scanf(" %lld",&n);
    a.clear();
    a.reserve(n);
    
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
    }
    dp[n-1]=dp[n]=0;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<=0||i+a[i]>=n)
        {
            dp[i]=dp[i+1];
            continue;
        }
        lli c=inv[a[i]-1]%mod;
        for(j=i+a[i];j<n;++j)
        {
            lli l=inv[j-i-a[i]];
            //cout<<"("<<j<<","<<i<<")"<<j-i-1<<" "<<a[i]-1<<endl;
            //cout<<"|"<<(((((fac[j-i-1]*l)%mod)*c)%mod)*(dp[j]+1))%mod<<"|"<<endl;
            dp[i]+=(((((fac[j-i-1]*l)%mod)*c)%mod)*(dp[j+1]+1))%mod;
            dp[i]%=mod;
        }
        dp[i]=(dp[i+1]+dp[i])%mod;
    }
    cout<<dp[0];
    aryanc403();
    return 0;
}