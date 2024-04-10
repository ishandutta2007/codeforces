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
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k,ans[50][3][3],p[3][3];
    vi :: iterator it;

lli check(lli n,lli i,lli j)
{
    if(ans[n][i][j]>=0)
    {
        return ans[n][i][j];
    }
    
    if(n==1)
    {
        return ans[n][i][j]=min(p[i][j],p[i][3-i-j]+p[3-i-j][j]);
    }
    ans[n][i][j]=p[i][j]+check(n-1,i,3-i-j)+check(n-1,3-i-j,j);
    ans[n][i][j]=min(ans[n][i][j],2*check(n-1,i,j)+p[i][3-i-j]+check(n-1,j,i)+p[3-i-j][j]);
    return ans[n][i][j];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    fo(k,50) fo(i,3) fo(j,3) ans[k][i][j]=-1;
    fo(i,3) fo(j,3)
    {
        scanf(" %lld",&p[i][j]);
    }
    
    scanf(" %lld",&n);
    cout<<check(n,0,2);
    return 0;
}