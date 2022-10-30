#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
const int maxn = 1005;
const int M = 1002;
const int inf = 1<<30;

char str[maxn];int n,c[maxn];
int b[maxn][maxn],len[maxn],a[maxn];
int srt[maxn][maxn],dig,rnk[maxn];
int f[maxn][maxn],g[maxn],h[maxn];

void read(int *f,int &len)
{
	scanf("%s",str);
	len=strlen(str);
	for (int i=0;i<len;i++)
	if (str[i]!='?')
		f[len-i]=str[i]-'0';
	else f[len-i]=-1;
}
bool comp(int u,int v)
{
	if (b[u][dig]!=b[v][dig])
		return b[u][dig]>b[v][dig];
	return rnk[u]<rnk[v];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("numbers.in","r",stdin);
		freopen("numbers.out","w",stdout);
	#endif
	read(a,len[0]);scanf("%d",&n);
	for (int i=1;i<=n;i++) read(b[i],len[i]);
	for (int i=1;i<=n;i++) len[i]=max(len[i],len[0]);
	for (int i=0;i<10;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) srt[0][i]=i;
	for (dig=1;dig<=M;dig++) {
		for (int i=1;i<=n;i++) srt[dig][i]=i;
		for (int i=1;i<=n;i++) rnk[srt[dig-1][i]]=i;
		sort(srt[dig]+1,srt[dig]+n+1,comp);
	}
	
	for (int j=1;j<=n;j++) f[0][j]=-inf;
	for (int i=1;i<=M;i++)
	for (int j=0;j<=n;j++) f[i][j]=-inf;
	
	for (int i=1;i<=M;i++)
	for (int w=0;w<=9;w++) {
		if (a[i]>=0&&a[i]!=w) continue;
		if (w==0&&i==len[0]) continue;
		for (int j=1;j<=n;j++)
			rnk[srt[i-1][j]]=j;
		for (int j=1;j<=n;j++) {
			int p=srt[i-1][j];
			g[j]=g[j-1]+c[(w+1+b[p][i])%10];
		}
		for (int j=n;j>=1;j--) {
			int p=srt[i-1][j];
			if (len[p]<i) h[j]=h[j+1];
			else h[j]=h[j+1]+c[(w+b[p][i])%10];
		}
		for (int j=0,k=0;j<=n;j++)
		{
			while (k<n) {
				int p=srt[i][k+1];
				if (w+b[p][i]+(rnk[p]<=j)>=10)
					++k;
				else break;
			}
			if (f[i-1][j]!=-inf)
				f[i][k]=max(f[i][k],f[i-1][j]+g[j]+h[j+1]);
		}
	}
	printf("%d",f[M][0]);
	return 0;
}