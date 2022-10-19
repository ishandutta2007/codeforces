#include<cstdio>
#include<cmath>
#define LL long long
int n,m,k,x,sq,cnt;
LL ans=0;
LL a[40002]={},b[40002]={};
bool cmp(int a,int b)
{
	return a>b? 1:0;
}
void init_a()
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x)++cnt;
		else if(cnt)
		{
			for(int j=cnt;j;j--)
				a[j]+=cnt-j+1;
			cnt=0;
		}
	}
	for(int i=cnt;i;i--)
		a[i]+=cnt-i+1;
}
void init_b()
{
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(x)++cnt;
		else if(cnt)
		{
			for(int j=cnt;j;j--)
				b[j]+=cnt-j+1;
			cnt=0;
		}
	}
	for(int j=cnt;j;j--)
		b[j]+=cnt-j+1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),sq=sqrt(k);
	init_a(),init_b();
	for(int i=1;i<=sq;i++)
		if(!(k%i))
		{
			if(i<=n && k/i<=m)ans+=a[i]*b[k/i];
			if(i!=k/i && k/i<=n && i<=m)ans+=a[k/i]*b[i];
		}
	printf("%lld",ans);
	return 0;
}