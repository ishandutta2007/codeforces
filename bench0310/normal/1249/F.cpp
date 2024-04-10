#include <bits/stdc++.h>

using namespace std;

const int N=205;
vector<int> v[N];
int e[N];
int dp[N][N];
int n,k;

void dfs(int a,int p=-1)
{
    for(int to:v[a]) if(to!=p) dfs(to,a);
    dp[a][0]=e[a];
    for(int c:v[a]) if(c!=p) dp[a][0]+=dp[c][k];
    for(int o=0;o<=n;o++) //distance from child to the closest selected vertex
    {
        if(o>k-1-o) break;
        for(int c:v[a]) //vertex with the shortest distance
        {
            if(c==p) continue;
            int now=dp[c][o];
            for(int d:v[a]) //other vertices
            {
                if(d==p||d==c) continue;
                now+=dp[d][k-1-o];
            }
            dp[a][o+1]=max(dp[a][o+1],now);
        }
    }
    for(int o=0;o<=n;o++)
    {
        if(2*o+2<=k) continue;
        int now=0;
        for(int c:v[a]) if(c!=p) now+=dp[c][o];
        dp[a][o+1]=max(dp[a][o+1],now);
    }
    for(int i=n;i>=0;i--) dp[a][i]=max(dp[a][i],dp[a][i+1]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&e[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    printf("%d\n",dp[1][0]);
    return 0;
}