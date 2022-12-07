#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int dp[5005][5005];
const int modo=998244353;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    dp[0][0]=1;
    int i;
    for (i=0;i<=5000;i++)
    {
        dp[0][i]=1;
        dp[i][0]=1;
    }
    int j;
    for (i=1;i<=5000;i++)
    {
        for (j=1;j<=5000;j++)
        {
            dp[i][j]=(dp[i-1][j]+(long long)dp[i-1][j-1]*j)%modo;
        }
    }
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(long long)dp[a][b]*dp[b][c]%modo*dp[c][a]%modo;
    return 0;
}