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
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,j,k;
    map <lli,lli> m;
    map <lli,lli> :: iterator it,jt,kt;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    lli l=s.size();
    lli cnt=0,ans=INF;
    string a;
    a=s;
    for(i=l-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            for(j=i+1;j<l;j++)
            {
                char c=s[j];
                s[j]=s[j-1];
                s[j-1]=c;
                cnt++;
            }
            //cout<<s<<" "<<cnt<<endl;
            for(lli k=l-2;k>=0;k--)
            {
                lli Cnt=0;
                string S=s;
                if(s[k]=='0'||s[k]=='5')
                {
                    for(j=k+1;j<l-1;j++)
                    {
                        char c=s[j];
                        s[j]=s[j-1];
                        s[j-1]=c;
                        Cnt++;
                    }
                    j=0;
                    //cout<<Cnt<<" ";
                    while(s[j]=='0')
                    {
                        j++;
                    }
                    if(s[0]!='0'||j<l-2)
                    {
                        //cout<<s<<endl;
                        ans=min(ans,cnt+Cnt+j);
                    }
                    s=S;
                }
            }
            s=a;
            cnt=0;
        }
    }s=a;
    cnt=0;
    for(i=l-1;i>=0;i--)
    {
        if(s[i]=='5')
        {
            for(j=i+1;j<l;j++)
            {
                char c=s[j];
                s[j]=s[j-1];
                s[j-1]=c;
                cnt++;
            }
            //cout<<s<<" "<<cnt<<endl;
            for(lli k=l-2;k>=0;k--)
            {
                lli Cnt=0;
                string S=s;
                if(s[k]=='2'||s[k]=='7')
                {
                    for(j=k+1;j<l-1;j++)
                    {
                        char c=s[j];
                        s[j]=s[j-1];
                        s[j-1]=c;
                        Cnt++;
                    }
                    j=0;
                    //cout<<Cnt<<" ";
                    while(s[j]=='0')
                    {
                        j++;
                    }
                    if(s[0]!='0'||j<l-2)
                    {
                        //cout<<s<<endl;
                        ans=min(ans,cnt+Cnt+j);
                    }
                    s=S;
                }
            }
            s=a;
            cnt=0;
        }
    }
    cout<<(ans==INF?-1:ans);
    return 0;
}