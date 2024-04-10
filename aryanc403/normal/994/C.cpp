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
    vi a;
    vi :: iterator it;

bool A[500][500];

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
void takeInput()
{
    vii s;
    lli i=0,x,y;
    fo(i,4)
    {
        cin>>x>>y;
        x+=100;
        y+=100;
        s.pb(mp(x,y));
    }
    sort(s.begin(),s.end(),cmp);
    
    for(lli i=s[0].X;i<=s[3].X;++i)
    for(lli j=s[0].Y;j<=s[3].Y;++j)
    {
        //cout<<i<<" "<<j<<endl;
        A[i][j]=true;
    }
}

bool takeInput2()
{
    vii s;
    lli i=0,x,y;
    fo(i,4)
    {
        cin>>x>>y;
        x+=100;
        y+=100;
        s.pb(mp(x,y));
    }
    sort(s.begin(),s.end(),cmp);
    lli d=s[3].X-s[0].X;
    x=s[0].X;y=s[0].Y;
    //cout<<d<<endl;
    //cout<<x<<" "<<y<<endl;
    for(lli i=0;i<=d/2;++i)
    {
        for(lli j=i;j<=d-i;++j)
        {
            //cout<<j+x<<" "<<i+y<<endl;cout<<j+x<<" "<<-i+y<<endl;
            if(A[j+x][i+y]||A[j+x][-i+y])
                return true;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    takeInput();
    if(takeInput2())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}