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

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool is=false;
    lli p;
    cin>>n>>p;
    cin>>s;
    //cout<<s;
    
    n-=p;
    fo(i,n)
    {
        if(s[i]=='.')
        {
            is=true;
            if(s[i+p]=='.')
            {
                s[i]='0';
                s[i+p]='1';
            }
            else if(s[i+p]=='0')
            {
                s[i]='1';
            }
            else if(s[i+p]=='1')
            {
                s[i]='0';
            }
        }
        else if(s[i]=='0')
        {
            if(s[i+p]=='.')
            {
                is=true;
                s[i+p]='1';
            }
            else if(s[i+p]=='1')
            {
                is=true;
            }
        }
        else if(s[i]=='1')
        {
            if(s[i+p]=='.')
            {
                is=true;
                s[i+p]='0';
            }
            else if(s[i+p]=='0')
            {
                is=true;
            }
        }
    }
    n+=p;
    for(;i<n;++i)
    {
        if(s[i]=='.')
            s[i]='0';
    }
    if(is)
    {
        cout<<s;
    }
    else
    {
        cout<<"No";
    }
    return 0;
}