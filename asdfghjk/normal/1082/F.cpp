#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,K,i,j,k,m[505],cnt=1,ch[505][15],w[505],dep[505],f[505][505][15],g[505][15],ans;
char s[505];
void dfs(int x)
{
	for(int j=0;j<=K;++j)
		f[x][dep[x]][j]=-(1<<30);
	f[x][dep[x]][1]=0;
	for(int y=0;y<=9;++y)
		if(ch[x][y])
		{
			dep[ch[x][y]]=dep[x]+1;
			dfs(ch[x][y]);
			w[x]+=w[ch[x][y]];
			for(int i=0;i<=dep[x];++i)
				for(int j=0;j<=K;++j)
					g[i][j]=-(1<<30);
			for(int i=0;i<=dep[x];++i)
				for(int j=0;j<=K;++j)
					for(int k=0;j+k<=K;++k)
						if(f[x][i][j]>-(1<<30)&&f[ch[x][y]][i][k]>-(1<<30))
							g[i][j+k]=max(g[i][j+k],f[x][i][j]+f[ch[x][y]][i][k]);
			for(int i=0;i<=dep[x];++i)
				for(int j=0;j<=K;++j)
					f[x][i][j]=g[i][j];
		}
	for(int j=0;j<=K;++j)
		if(f[x][dep[x]][j]>-(1<<30))
		{
			for(int i=0;i<dep[x];++i)
				f[x][i][j]=max(f[x][i][j],f[x][dep[x]][j]+w[x]*(dep[x]-i));
		}
	/*for(int i=0;i<=dep[x];++i)
		for(int j=0;j<=K;++j)
			if(f[x][i][j]>-(1<<30))
				printf("%d %d %d %d\n",x,i,j,f[x][i][j]);*/
}
int main()
{
	scanf("%d%d",&n,&K);
	++K;
	for(i=1;i<=n;++i)
	{
		scanf("%s%d",s+1,m+i);
		for(j=1,k=1;s[j];++j)
		{
			if(!ch[k][s[j]-'0'])
				ch[k][s[j]-'0']=++cnt;
			k=ch[k][s[j]-'0'];
		}
		w[k]+=m[i];
		ans+=(j-1)*m[i];
	}
	dfs(1);
	j=0;
	for(i=0;i<=K;++i)
		j=max(j,f[1][0][i]);
	ans-=j;
	printf("%d",ans);
	return 0;
}