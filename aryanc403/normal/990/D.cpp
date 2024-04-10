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

    lli T,n,in,i,m,j,k,a,b;
    lli mat [1005][1005];
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    
    if(((m=min(a,b))>1)||(n>1&&n<=3&&a==1&&b==1))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    
    
    if(a==1&&b==1)
    {
        for(i=a+b-m;i<n;++i)
        {
            mat[i][i+1]=mat[i+1][i]=1;
        //cout<<i<<" "<<i+1<<endl;
        }
        
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(i==j)
                    cout<<0;
                else
                    cout<<mat[i][j];
            }
            cout<<endl;
        }
        
        return 0;
    }
    
    
    
    for(i=a+b-m;i<n;++i)
    {
        mat[i][i+1]=mat[i+1][i]=1;
        //cout<<i<<" "<<i+1<<endl;
    }
    bool chg=(a==m);
    
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(i==j)
                cout<<0;
            else if(chg)
                cout<<(!(mat[i][j]));
            else
                cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}