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
const lli INF = 0xFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;

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

    lli T,n,i,m,j,k;
    lli sz[200005],fsz[200005],h[200005];
    vi :: iterator it;
    bool al[200005];
    lli dp[5002][502];
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

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
lli sol(lli s,lli p)
{
    if(s<0||p<0)
        return -INF;
    if(s>=k*p)
        return p*h[k];
    if(dp[s][p])
        return dp[s][p];
    lli cnt=0;
    
    for(lli i=0;i<=k;++i)
    {
        cnt=max(cnt,h[i]+sol(s-i,p-1));
    }
    
    dp[s][p]=cnt;
    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli in;
    scanf(" %lld %lld",&n,&k);
    n=n*k;
    fo(i,n)
    {
        scanf(" %lld",&in);
        sz[in]++;
    }
    n/=k;
    fo(i,n)
    {
        scanf(" %lld",&in);
        fsz[in]++;
    }
    fo(i,k)
    {
        scanf(" %lld",&h[i+1]);
    }
    lli cnt=0;
    lli lim=(1<<k);
    for(i=1;i<=100000;++i)
    {
        lli p=fsz[i];
        lli s=sz[i];
        cnt+=sol(s,p);
    }
    printf("%lld\n",cnt);
    aryanc403();
    return 0;
}