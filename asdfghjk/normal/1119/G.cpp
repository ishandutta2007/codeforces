#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2000005;
struct node
{
	int id,num;
}w[N];
int n,m,s,hp[N],a[N],p[N],cnt,atk[N],i,j,k,x,y,id[N],tot;
bool cmp(node a,node b)
{
	return a.num<b.num;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",hp+i);
		s+=hp[i];
	}
	printf("%d\n",tot=(s-1)/n+1);
	s=0;
	for(i=1;i<=m;++i)
	{
		s+=hp[i];
		s%=n;
		p[i]=s;
	}
	p[m]=n;
	sort(p+1,p+1+m);
	for(i=1;i<=m;++i)
	{
		atk[i]=p[i]-p[i-1];
		printf("%d ",atk[i]);
	}
	puts("");
	for(i=1,j=1;i<=m;++i)
	{
		while(hp[i]>0)
		{
			printf("%d ",i);
			hp[i]-=atk[j];
			if(j==m)
			{
				--tot;
				puts("");
				j=1;
			}
			else
				++j;
		}
	}
	while(tot--)
	{
		while(j<=m)
		{
			printf("1 ");
			++j;
		}
		puts("");
		j=1;
	}
	return 0;
}