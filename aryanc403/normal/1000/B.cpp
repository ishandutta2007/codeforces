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

    lli T,n,i,m,j,k,in;
    vi a;
    vi :: iterator it;
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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&m);
    a.reserve(n+2);
    a.clear();
    a.pb(0);
    fo(i,n)
    {
        scanf(" %lld",&in);
        //cout<<in;
        a.pb(in);
    }
    a.pb(m);
    lli ans=0;
    lli sum=0;
    //fo(i,n+2)
        //cout<<a[i]<<" ";
    //cout<<endl;
    for(i=1;i<=n+1;++i)
    {
        if(i%2)
        {
            ans+=a[i]-a[i-1];
        }
        else
        {
            sum+=a[i]-a[i-1];
        }
    }
    lli cnt=0;
    //cout<<ans<<endl;
    for(i=1;i<=n+1;++i)
    {
        if(i%2)
        {
            if(a[i]!=a[i-1]+1)
                ans=max(ans,cnt+a[i]-a[i-1]-1+sum);
            //cout<<a[i]<<" "<<cnt+a[i]-a[i-1]-1+sum<<" c"<<cnt<<" s"<<sum<<endl;
            cnt+=a[i]-a[i-1];
        }
        else
        {
            sum-=a[i]-a[i-1];
            if(a[i]!=a[i-1]+1)
                ans=max(ans,cnt+a[i]-a[i-1]-1+sum);
            //cout<<a[i]<<" "<<cnt+a[i]-a[i-1]-1+sum<<" c"<<cnt<<" s"<<sum<<endl;
        }
    }
    
    cout<<ans;
    aryanc403();
    return 0;
}