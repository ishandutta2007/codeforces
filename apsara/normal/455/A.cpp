#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
const int N=100000;
int a[V],n,x;
LL dp[V];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x]++;
        }
        LL ret=0;
        dp[N+1]=0;
        dp[N+2]=0;
        for(int i=N;i>0;i--)
        {
            dp[i]=max(dp[i+2]+(LL)a[i]*i,dp[i+1]);
        }
        cout<<dp[1]<<endl;
    }
    return 0;
}