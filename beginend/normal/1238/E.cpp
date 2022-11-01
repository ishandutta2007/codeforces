#include<bits/stdc++.h>

const int N=25;
const int M=1048580;
const int inf=1000000000;

int n,m,bin[N],sz[M],s[N][M],cnt[N][N],f[M];
char str[100005];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	bin[0]=1;
	for (int i=1;i<=m;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<n;i++)
	{
		int x=str[i]-'a',y=str[i+1]-'a';
		if (x==y) continue;
		cnt[x][y]++;cnt[y][x]++;
	}
	for (int i=1;i<bin[m];i++) sz[i]=sz[i-(i&(-i))]+1;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<m;j++) s[i][bin[j]]=cnt[i][j];
		for (int j=1;j<bin[m];j++) s[i][j]=s[i][j-(j&(-j))]+s[i][j&(-j)];
	}
	for (int i=1;i<bin[m];i++)
	{
		f[i]=inf;
		for (int j=0;j<m;j++)
			if (i&bin[j])
			{
				int s1=i-bin[j],s2=bin[m]-1-i;
				f[i]=std::min(f[i],f[s1]+(sz[s1]+1)*(s[j][s1]-s[j][s2]));
			}
	}
	printf("%d\n",f[bin[m]-1]);
	return 0;
}