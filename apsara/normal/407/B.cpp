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
const int V=1200;
const int P=1000000007;
int dp[V],p[V],n;
int main()
{
    while(~scanf("%d",&n))
    {   
        for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
        dp[1]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i+1]=(2*dp[i]%P+2-dp[p[i]]+P)%P;
        }
        printf("%d\n",dp[n+1]);
    }
}