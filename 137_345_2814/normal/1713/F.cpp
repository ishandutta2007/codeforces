#include<cstdio>
using namespace std;
#define N 530001
int n,m,v[N],sr[N],as[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int d=18;d>=0;d--)if((n>>d)&1)
	{
		for(int i=0;i<1<<d;i++)sr[i]=v[m+(1<<d)-i];
		for(int l=1;l<1<<d;l<<=1)for(int i=0;i<1<<d;i++)if(i&l)sr[i]^=sr[i^l];
		for(int i=0;i<m;i++)if((i&m)==0)sr[i&((1<<d)-1)]^=as[i];
		for(int i=m;;i=(i-1)&m)
		{
			for(int j=0;j<1<<d;j++)as[i+j]^=sr[j];
			if(!i)break;
		}
		m+=1<<d;
	}
	for(int i=m-1;i>=0;i--)printf("%d ",as[i]);
}