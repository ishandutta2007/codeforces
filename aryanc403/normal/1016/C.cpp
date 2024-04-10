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
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
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

class cmp
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return a > b;
    }
};

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

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l;
    vi a[2],dp[4];
    lli sum[2],sol[4],t;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    a[0].clear();a[0].reserve(n);
    a[1].clear();a[1].reserve(n);
    
    fo(i,n)
    {
        scanf(" %lld",&in);
        a[0].pb(in);
        sum[0]+=in;
        sol[0]+=(i)*in;
    }
    
    fo(i,n)
    {
        scanf(" %lld",&in);
        a[1].pb(in);
        sum[1]+=in;
        sol[1]+=(i)*in;
    }
    
    fo(i,n)
    {
        sol[3]+=(i+1)*a[0][n-1-i];
        sol[2]+=(i+1)*a[1][n-1-i];
    }
    
    lli ans;
    cnt=ans=0;
    t=0;
    fo(i,n)
    {
        if(i%2)
        {
            //cout<<sol[1]<<" s";
            ans=max(ans,cnt+sol[1]+(t)*sum[1]+sol[3]+(t+n-i-1)*sum[0]);
            cnt+=t*a[1][i];
            t++;
            sum[1]-=a[1][i];
            sol[1]-=sum[1];
            sol[2]-=(n-i)*a[1][i];
            //cout<<ans<<endl;
            
            ans=max(ans,cnt+sol[0]+(t)*sum[0]+sol[2]+(t+n-i-1)*sum[1]);
            cnt+=t*a[0][i];
            t++;
            sum[0]-=a[0][i];
            sol[0]-=sum[0];
            sol[3]-=(n-i)*a[0][i];
            //cout<<ans<<endl;
        }
        else
        {
            //cout<<sol[2]<<" ";
            ans=max(ans,cnt+sol[0]+(t)*sum[0]+sol[2]+(t+n-i-1)*sum[1]);
            cnt+=t*a[0][i];
            t++;
            sum[0]-=a[0][i];
            sol[0]-=sum[0];
            sol[3]-=(n-i)*a[0][i];
            //cout<<ans<<endl;
            
            //cout<<sol[1]<<" s"<<endl;
            ans=max(ans,cnt+sol[1]+(t)*sum[1]+sol[3]+(t+n-i-1)*sum[0]);
            cnt+=t*a[1][i];
            t++;
            sum[1]-=a[1][i];
            sol[1]-=sum[1];
            sol[2]-=(n-i)*a[1][i];
            //cout<<ans<<endl;
        }
    }
    
    printf("%lld\n",ans);
    aryanc403();
    return 0;
}