#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5005;

int n,m,r;
char s[N],ans[N];
bool f[N],g[N];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (r=1;r*2<=n;r*=2);
	m=n-r+1;
	for (int i=0;i<r;i++) f[i]=1;
	for (int i=1;i<=m;i++)
	{
		ans[i]='z';
		for (int j=0;j<r;j++) if (f[j]&&s[i+j]<ans[i]) ans[i]=s[i+j];
		memset(g,0,sizeof(g));
		for (int j=0;j<r;j++)
			if (f[j]&&s[i+j]==ans[i]&&!g[j])
			{
				int w=r-1-j;
				for (int s=w;s;s=(s-1)&w) g[r-1-s]=1;
				g[r-1]=1;
			}
		for (int j=0;j<r;j++) f[j]=g[j];
	}
	for (int i=1;i<=m;i++) putchar(ans[i]);
	return 0;
}