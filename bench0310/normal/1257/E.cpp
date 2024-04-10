#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k[4];
    for(int o=1;o<=3;o++) scanf("%d",&k[o]);
    int n=k[1]+k[2]+k[3];
    vector<int> v(n);
    for(int o=1;o<=3;o++)
    {
        for(int i=0;i<k[o];i++)
        {
            int t;
            scanf("%d",&t);
            v[t-1]=o;
        }
    }
    int dp[n][4];
    for(int i=0;i<n;i++) dp[i][0]=n;
    for(int o=1;o<=3;o++)
    {
        int m=0;
        for(int i=0;i<n;i++)
        {
            m=min(m+(v[i]!=o),dp[i][o-1]);
            dp[i][o]=m;
        }
    }
    printf("%d\n",dp[n-1][3]);
    return 0;
}