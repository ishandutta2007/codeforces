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
    vii a;
    vi :: iterator it;
    char mat[55][55];

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

void print()
{
    lli i,j;
cout<<n<<" "<<m<<endl;
    fo(i,n)
    {
        fo(j,m)
        {
            cout<<(char)mat[i][j];
        }
        cout<<endl;
    }
}

void seT(char a)
{
    lli i,j;
    fo(i,n) fo(j,m) mat[i][j]=a;
}

void setFinal(char a, lli cnt)
{
    i++;
    i++;

if(cnt<=0)
{
   return;
}

    for(;i<n;i+=2)
    {
        for(j=0;j<m;j+=2)
        {
            mat[i][j]=a;
            cnt--;
            if(cnt<=0)
                return;
        }
    }
}

lli setInt(char a, char b, lli cnt)
{
            if(cnt<=0)
            {
                return 1;
            }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;j+=2)
        {
            mat[i][j]=a;
            mat[i][j+1]=b;
            
            cnt--;
            if(cnt<=0)
            {
                j+=2;
                return 1;
            }
        }
        
        i++;
        for(j=m-1;j>=0;j-=2)
        {
            mat[i][j]=a;
            mat[i][j-1]=b;
            
            cnt--;
            if(cnt<=0)
            {
                j-=2;
                return -1;
            }
        }
    }
}
void setOneLine(char a)
{
    fo(j,m)     mat[i][j]=a;
    j=0;
    i++;
}

void setCur(lli inc,char a)
{
	for(;j<m&&j>=0;j+=inc)
	{
	    mat[i][j]=a;
	}
	i++;
	j=0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    m=n=50;
    fo(i,4)
    {
        cin>>in;
        a.pb(mp(in,'A'+i));
    }
    sort(a.begin(),a.end());
    i=j=0;
    bool isC=(a[0].X!=26);
    seT(a[0].Y);
    a[0].X--;
    setCur(setInt(a[0].Y,a[1].Y,a[0].X),a[2].Y);
    a[1].X-=a[0].X;
    if(isC)
        a[2].X--;
    setOneLine(a[3].Y);
    a[3].X--;
    
    setFinal(a[1].Y,a[1].X);
    setFinal(a[2].Y,a[2].X);
    setFinal(a[3].Y,a[3].X);
    print();
    return 0;
}