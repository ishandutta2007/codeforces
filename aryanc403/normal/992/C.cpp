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

    lli T,n,in,i,m,j,k,x;
    vi a;
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

lli po(lli k)
{
    if(k==0)
        return 1;
    lli c=po(k/2);
    c=(c*c)%MOD;
    if(k%2)
        c=(2*c)%MOD;
    return c;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>k;
    if(k==0||x==0)
    {
        cout<<(2*x)%MOD;
        return 0;
    }
    lli a = po(k);
    x=(2*x-1)%MOD;
    cout<<(a*x+1)%MOD;
    
    return 0;
}