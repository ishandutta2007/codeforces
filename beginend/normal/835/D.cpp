#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;

const int N=5005;

int n,ans[N],hash[N][N],f[N][N];
char s[N];
bool vis[N][N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) vis[i][i]=vis[i][i-1]=1;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			vis[i][j]=(s[i]==s[j]&&vis[i+1][j-1]);
		}
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			if (!vis[i][j]) continue;
			int len=(j-i+1)/2;
			f[i][j]=f[i][i+len-1]+1;
		}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			ans[f[i][j]]++;
	for (int i=n;i>=1;i--) ans[i]+=ans[i+1];
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}