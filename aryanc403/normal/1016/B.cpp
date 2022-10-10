//Ref - My own soln on CodeChef - https://www.codechef.com/viewplaintext/19423064
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
const lli mod[3] ={ 999119999L,1000000007L,1000992299L};
const lli bas[3] ={ 97L,101L,103L};

    lli T,n,in,i,m,j,k,l,q,dp1[1005];
    vi a[3],b[3];
    vi po[3];
    vi :: iterator it;
    string s,t;

void setHash()
{
    a[0].clear();a[1].clear();a[2].clear();
    b[0].clear();b[1].clear();b[2].clear();
    a[0].pb(0);a[1].pb(0);a[2].pb(0);
    b[0].pb(0);b[1].pb(0);b[2].pb(0);
    
    fo(i,n) fo(j,3)
    {
        a[j].pb((a[j][i]*bas[j]+s[i])%mod[j]);
    }
    
    fo(i,m) fo(j,3)
    {
        b[j].pb((b[j][i]*bas[j]+t[i])%mod[j]);
    }
    
}

void pre(lli n)
{
    po[0].pb(1);
    po[1].pb(1);
    po[2].pb(1);
    lli i;
    fo(i,n)
    {
        po[0].pb((po[0][i]*bas[0])%mod[0]);
        po[1].pb((po[1][i]*bas[1])%mod[1]);
        po[2].pb((po[2][i]*bas[2])%mod[2]);
    }
}

lli dp[1005][1005];

lli check(lli i)
{
    lli c=0,k=0,x=0,y=0;
    for(lli k=0;k<3;++k)
    {
        x=(a[k][i+m]-(a[k][i]*po[k][m])%mod[k])%mod[k];
        x=(x+mod[k])%mod[k];
        
        y=(b[k][m]-(b[k][0]*po[k][m])%mod[k])%mod[k];
        y=(y+mod[k])%mod[k];
        
        if(x!=y)
            return 0;
    }    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    cin>>s;
    cin>>t;
    pre(n);
    //cout<<s<<endl<<t<<endl;return 0;
    setHash();
    //for(lli i=0;i+m<n;++i)
    {
      //  dp[i][i+m-1]=check(i);
    }
    
    for(i=0;i<n;i++)
        dp1[i]=check(i);
    
    for(i=0;i<n;i++)
    {
        for(j=i+m-1;j<n;j++)
            dp[i][j]=dp[i][j-1]+dp1[j-m+1];
    }
    lli l,r;
    while(q--)
    {
        cin>>l>>r;
        l--;r--;
        cout<<dp[l][r]<<endl;
    }
    return 0;
}