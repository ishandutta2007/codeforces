#include<cstdio>
#include<cstring>
int n,m,d,d1=0,d2=0,a[8],ans=0;
bool visit[8];
void dfs(int k)
{
	if(k>d)
	{
		int p=0,q=0,pw=1;
		for(int j=d1;j>=1;j--)p+=a[j]*pw,pw*=7;
		pw=1;
		for(int j=d;j>d1;j--)q+=a[j]*pw,pw*=7;
		if(p<n&&q<m)ans++;
		return;
	}
	for(int i=0;i<7;i++)if(!visit[i])
	{
		a[k]=i;
		visit[i]=true;
		dfs(k+1);
		visit[i]=false;
	}
}
int main()
{
	memset(visit,0,sizeof(visit));
	scanf("%d%d",&n,&m);
	int p=n-1,q=m-1;
	while(p)p/=7,d1++;
	while(q)q/=7,d2++;
	if(n==1)d1=1;
	if(m==1)d2=1;
	d=d1+d2;
	if(d>7)
	{
		printf("0\n");
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}