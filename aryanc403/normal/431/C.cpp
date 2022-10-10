/************************************************************************************************************************************************************************************
  *                                                                                                                                                                                  *
  *                                                                                                                                                                                   *                                                                                                                                                                                  *
  *                                                                                                                                                                                    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
  *                                                                                                                                                                                     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
  *                                                                                                                                                                                      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
  *                                                                                                                                                                                       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
  *                                                                                                                                                                                        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
  *                                                                                                                                                                                         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
  *                                                                                                                                                                                          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
  *                                                                                                                                                                                           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
  *                                                                                                                                                                                            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
  *                                                                                                                                                                                             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
  *                                                                                                                                                                                              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
  *                                                                                                                                                                                               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
  *                                                                                                                                                                                                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
  *                                                                                                                                                                                                 *                                                                                                                                                                                  *
  *                                                                                                                                                                                                  *                                                                                                                                                                                  *
  *                                                                                                                                                                                                   ************************************************************************************************************************************************************************************/

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
lli T,n,in,i,m,j,K;
lli dp[105][105][105];
vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli d;
    cin>>n>>K>>d;

    for(lli j=1;j<=K;++j)
        for(lli i=1;i<=n&&i<=j;++i)
            dp[i][j][1]=1;

    for(lli k=2;k<=n;++k)//moves
        for(lli j=1;j<=K;++j)
        {
            for(lli i=1;i<=n;++i)
            {
                for(lli l=1;l<=j&&l<=i;++l)
                {
                    dp[i][j][k]+=dp[i-l][j][k-1];
                    if(dp[i][j][k]>=MOD)
                        dp[i][j][k]%=MOD;

                }
                //cout<<"moves "<<k<<"sum "<<i<<"limit "<<j<<"ans"<<dp[i][j][k]<<endl;

            }

        }
    lli cnt=0;
    for(i=0;i<=n;++i)
    {
        cnt+=dp[n][K][i]-dp[n][d-1][i];
        if(cnt>=MOD||cnt<=-MOD)
            cnt%=MOD;
    }
    
    cnt=(cnt+MOD)%MOD;
    cout<<cnt;
    return 0;

}