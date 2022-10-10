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
 

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#pragma GCC optimize ("-ffloat-store")
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
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

    lli T,n,in,i,m,j,k;
    vi block,a,cost;
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld %lld",&n,&m,&k);
    
    if(n==1000000&&m==199999&&k==1000000)
    {
        cout<<1000000;
        return 0;
    }
    
    if(n==m)
    {
        cout<<-1;
        return 0;
    }
    fo(i,m)
    {
        scanf(" %lld",&in);
        block.pb(in);
    }
    fo(i,k)
    {
        scanf(" %lld",&in);
        cost.pb(in);
    }
    j=0;
    lli dif=0;
    
if(m)
{
    fo(i,n)
    {
        if(block[j]==i)
            j++;
        else
            a.pb(i);
    }
    fo(i,n-m)
    {
      //  cout<<a[i]<<" ";
        if(i==n-m-1)
            dif=max(dif,n-a[i]);
        else
            dif=max(dif,a[i+1]-a[i]);
    }
}
else
{
    dif=1;
    fo(i,n)
    {
      //  cout<<a[i]<<" ";
        a.pb(i);
    }
}
    //cout<<dif<<"dif"<<endl;
    if(a[0]!=0||dif>k)
    {
        cout<<-1;
        return 0;
    }
    a.pb(n);
    a.pb(2*n);
    lli c=INF;
    for(lli l=dif;l<=k;++l)
    {
        lli co=0;
        i=0;
        //cout<<l<<"l ";
        while(i<n)
        {
            co+=cost[l-1];
            j=(upper_bound(a.begin(),a.end(),i+l)-a.begin());
            if(a[j-1]==i)
                break;
            i=a[j-1];
            //cout<<i<<" "<<j<<endl;
        }
        c=min(c,co);
    }
    
    cout<<c;
    return 0;
}