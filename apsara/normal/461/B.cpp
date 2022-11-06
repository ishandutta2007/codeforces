#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int>V[200011];
int col[100111];
long long dp[100111][2];
long long MOD=1000000007;
void dfs(int pos,int last)
{
    dp[pos][0]=(!col[pos]);
    dp[pos][1]=(col[pos]);
    int len=V[pos].size();
    for(int i=0;i<len;i++)
    {
        int v=V[pos][i];
        if(v==last)
            continue;
        dfs(v,pos);
        long long d0=dp[pos][0]*(dp[v][0]+dp[v][1]);
        long long d1=dp[pos][0]*dp[v][1]+dp[pos][1]*dp[v][1]+dp[pos][1]*dp[v][0];
        dp[pos][0]=d0%MOD;
        dp[pos][1]=d1%MOD;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        V[i].push_back(b);
        V[b].push_back(i);
    }
    for(int i=0;i<n;i++)
        scanf("%d",&col[i]);
    dfs(0,-1);
    printf("%I64d\n",dp[0][1]);
}