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

    lli T,n,in,i,m,j,k,ans[100005];
    vii a;
    vi c;
    bool b[20];
bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    fo(i,n)
    {
        cin>>in;
        a.pb(mp(in,i));
    }
    fo(i,n)
    {
        cin>>in;
        c.pb(in);
        ans[i]=in;
    }
    sort(a.begin(),a.end(),cmp);
    
    if(k==0)
    {
        fo(i,n)
        {
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    
    priority_queue <lli> q;
    lli sum=0;
    lli sz=0;
    for(i=0;i<n;++i)
    {
        ans[a[i].Y]+=sum;
        if(sz<k)
        {
            q.push(-c[a[i].Y]);
            sum+=c[a[i].Y];
            sz++;
        }
        else if(sz&&-q.top()<c[a[i].Y])
        {
            //cout<<-q.top()<<" ";
            sum+=q.top();
            q.pop();
            q.push(-c[a[i].Y]);
            sum+=c[a[i].Y];
        }
    }
    // while(sz)
    // {
    //     cout<<-q.top()<<" ";
    //     q.pop();sz--;
    // }
    // cout<<endl;
    fo(i,n)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}