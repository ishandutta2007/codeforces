#include<bits/stdc++.h>
using namespace std;
int n,q,i,f[100005],p[100005],a[100005],b[100005],k,y[100005],col[100005],t;
char c[100005];
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[y]=x;
}
void Q()
{
	if(k==0)
		return;
	int i;
	printf("Q %d ",k);
	for(i=1;i<=k;++i)
		printf("%d %d ",a[i],b[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",c+1);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=0;
		memset(f,0,sizeof(f));
		for(i=1;i+1<=n;i+=2)
		{
			a[++k]=i;
			b[k]=i+1;
		}
		Q();
		for(i=1;i<=k;++i)
			if(c[i]=='1')
				uniot(2*i-1,2*i);
		k=0;
		for(i=2;i+1<=n;i+=2)
		{
			a[++k]=i;
			b[k]=i+1;
		}
		Q();
		for(i=1;i<=k;++i)
			if(c[i]=='1')
				uniot(2*i,2*i+1);
		k=0;
		int m=0;
		for(i=1;i<=n;++i)
			if(f[i]==0)
				p[++m]=i;
		for(i=1;i+2<=m;i+=4)
		{
			a[++k]=p[i];
			b[k]=p[i+2];
		}
		for(i=2;i+2<=m;i+=4)
		{
			a[++k]=p[i];
			b[k]=p[i+2];
		}
		Q();
		for(i=1;i<=k;++i)
			y[b[i]]=c[i]-'0';
		k=0;
		for(i=3;i+2<=m;i+=4)
		{
			a[++k]=p[i];
			b[k]=p[i+2];
		}
		for(i=4;i+2<=m;i+=4)
		{
			a[++k]=p[i];
			b[k]=p[i+2];
		}
		Q();
		for(i=1;i<=k;++i)
			y[b[i]]=c[i]-'0';
		col[p[1]]=1;
		col[p[2]]=2;
		for(i=3;i<=m;++i)
			if(y[p[i]])
				col[p[i]]=col[p[i-2]];
			else
				if((col[p[i-1]]==1&&col[p[i-2]]==2)||(col[p[i-1]]==2&&col[p[i-2]]==1))
					col[p[i]]=3;
				else
					if((col[p[i-1]]==2&&col[p[i-2]]==3)||(col[p[i-1]]==3&&col[p[i-2]]==2))
						col[p[i]]=1;
					else
						col[p[i]]=2;
		int cnt=0;
		for(i=1;i<=n;++i)
			if(col[Find(i)]==1)
				++cnt;
		printf("A %d ",cnt);
		cnt=0;
		for(i=1;i<=n;++i)
			if(col[Find(i)]==2)
				++cnt;
		printf("%d ",cnt);
		cnt=0;
		for(i=1;i<=n;++i)
			if(col[Find(i)]==3)
				++cnt;
		printf("%d\n",cnt);
		for(i=1;i<=n;++i)
			if(col[Find(i)]==1)
				printf("%d ",i);
		printf("\n");
		for(i=1;i<=n;++i)
			if(col[Find(i)]==2)
				printf("%d ",i);
		printf("\n");
		for(i=1;i<=n;++i)
			if(col[Find(i)]==3)
				printf("%d ",i);
		printf("\n");
		fflush(stdout);
	}
}