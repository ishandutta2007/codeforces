#include"bits/stdc++.h"
using namespace std;
int dp[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q,d;
        cin>>q>>d;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<=100;i++)
        {
            if(dp[i])
            {
                for(int j=0;j<10;j++)
                {
                    dp[10*j+d+i]=1;
                    dp[d*10+j+i]=1;
                }
            }
        }
        while(q--)
        {
            int n;
            scanf("%d",&n);
            if(n>=100)puts("yes");
            else if(dp[n])puts("yes");
            else puts("no");
        }
    }
    return 0;
}