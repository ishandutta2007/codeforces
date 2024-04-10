#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int v[n][m],dp[n][m];

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&v[i][j]);

    for(int j=0;j<m;++j)
    {
        dp[0][j]=0;
        for(int i=1;i<n;++i)
        {
            dp[i][j]=(v[i][j]>=v[i-1][j])?dp[i-1][j]:i;
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=1;j<m;++j)
            dp[i][0]=min(dp[i][0],dp[i][j]);
    }

    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        int l,r;
        cin>>l>>r;
        --l,--r;
        printf(dp[r][0]<=l?"Yes\n":"No\n");
    }
    return 0;
}