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
    lli T,n,in,i,j,k,l;
    map<lli,lli> m;
    map<lli,lli> :: iterator it,jt,kt;

string s;
    

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

void add(lli c)
{
    kt=m.find(c);
    if(kt==m.end())
        m.insert(mp(c,1));
    else
        kt->Y++;
}

lli fin(lli c)
{
    kt=m.find(c);
    if(kt==m.end())
        return 0;
    else
        return kt->Y;
}

bool isValid(lli cnt)
{
    fo(i,l)
    {
        if(s[i]=='(')
            cnt++;
        else if(s[i]==')')
        {
            if(cnt<=0)
                return false;
            cnt--;
        }
    }
    return true;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--)
    {
        cin>>s;
        l=s.size();
        lli cnt=0;
        fo(i,l)
        {
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
                cnt--;
        }
        if(isValid(cnt<0?-cnt:0))
            add(cnt);
    }
    lli cnt=0;
    for(it=m.begin();it!=m.end()&&it->X<=0;++it)
    {
        cnt+=(it->Y)*(fin(-(it->X)));
    }
    cout<<cnt;
    return 0;
}