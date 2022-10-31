#include<bits/stdc++.h>

typedef long long LL;

const int N=100005;

int n,p,k,id[N],a[N],w[N][10],bin[10],cnt[150];
LL f[N][150];

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=0;j<p;j++)
			scanf("%d",&w[i][j]);
	std::sort(id+1,id+n+1,cmp);
	bin[0]=1;
	for (int i=1;i<=p;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<bin[p];i++) cnt[i]=cnt[i-(i&(-i))]+1;
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<bin[p];j++)
		{
			int x=id[i];
			if (i-cnt[j]<=k&&f[i-1][j]) f[i][j]=std::max(f[i][j],f[i-1][j]+a[x]);
			else if (f[i-1][j]) f[i][j]=std::max(f[i][j],f[i-1][j]);
			for (int l=0;l<p;l++)
				if ((j&bin[l])&&f[i-1][j-bin[l]]) f[i][j]=std::max(f[i][j],f[i-1][j-bin[l]]+w[x][l]);
		}
	printf("%lld\n",f[n][bin[p]-1]-1);
	return 0;
}