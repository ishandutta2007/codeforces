#include<cstdio>
int n;
int x[1002],y[1002],cnt[2];
bool u[1002];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	while(1)
	{
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;++i)++cnt[u[i]=((x[i]^y[i])&1)];
		if(cnt[0] && cnt[1])break;
		if(cnt[1])for(int i=1;i<=n;++i)--x[i];
		for(int i=1;i<=n;++i)x[i]=(x[i]-y[i])/2,y[i]+=x[i];
	}
	printf("%d\n",cnt[0]);
	for(int i=1;i<=n;++i)if(!u[i])printf("%d ",i);
	return 0;
}