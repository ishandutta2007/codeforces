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
    lli T,n,in,i,m,j,k;
    vi a;
    //vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    //cout<<s<<" "<<t;
    lli ans[256];
    vector < pair<char,char> > a;
    vector < pair<char,char> > :: iterator it;
    lli l=s.size();
    fo(i,256)
        ans[i]=-1;
    fo(i,l)
    {
        if(ans[s[i]]==-1&&ans[t[i]]==-1)
        {
            if(s[i]!=t[i])
                a.pb(mp(s[i],t[i]));
            ans[s[i]]=t[i];
            ans[t[i]]=s[i];
        }
        if(ans[s[i]]!=t[i]||ans[t[i]]!=s[i])
        {
            cout<<-1;
            return 0;
        }
    }
    
    l=a.size();
    cout<<l<<endl;
    
    for(it=a.begin();it!=a.end();++it)
    {
        cout<<it->X<<" "<<it->Y<<endl;
    }
    
    return 0;
}