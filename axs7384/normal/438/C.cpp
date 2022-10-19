#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 222
struct node
{
    ll x,y;
    node operator-(const node&b)const
    {
        node c;
        c.x=x-b.x,c.y=y-b.y;
        return c;
    }
    ll operator*(const node&b)const
    {
        return x*b.y-y*b.x;
    }
}p[maxn];
const ll mod=1e9+7ll;
ll dp[maxn][maxn];
int n;
ll dfs(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i+1==j)return dp[i][j]=1;
    ll ans=0;
    for(int k=i+1;k<j;k++)
        if((p[k]-p[i])*(p[j]-p[i])>0)
            ans=(ans+dfs(i,k)*dfs(k,j)%mod)%mod;
    return dp[i][j]=ans;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)scanf("%I64d%I64d",&p[i].x,&p[i].y);
        ll s=0;
        for(int i=0;i<n;i++)s+=p[i]*p[(i+1)%n];
        if(s<0)
            for(int i=0,j=n-1;i<j;i++,j--)swap(p[i],p[j]);
        printf("%I64d\n",dfs(0,n-1));
    }
    return 0;
}