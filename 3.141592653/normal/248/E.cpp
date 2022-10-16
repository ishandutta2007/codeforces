#include<cstdio>
int n,q,a[1111111],b[1111111];
typedef double db;
db dp[111111][111],ans;
void remove(int x)
{
	ans-=dp[x][0];
	for(register int i=0;i<=a[x];i++)
		dp[x][i]=dp[x][i]*(b[x]-i)/b[x]+dp[x][i+1]*(i+1)/b[x];
	b[x]--;
	ans+=dp[x][0];
}
void mov(int x,int y,int v)
{
	for(register int i=1;i<=v;i++)remove(x);b[y]+=v;
}
int main()
{
    register int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i),dp[i][a[i]]=1,b[i]=a[i],ans+=1.0*(!a[i]);
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
    	int x,y,v;
    	scanf("%d%d%d",&x,&y,&v),mov(x,y,v);
    	printf("%.12lf\n",ans);
    }
}