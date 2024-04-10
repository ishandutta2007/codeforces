#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 3005;
const int inf = 1<<30;

int a[maxn],n,m,sum,ord[maxn];
char stand[maxn];
char str[maxn][maxn];
int ans[maxn][maxn];
bool comp(int x,int y) {return a[x]>a[y];}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("chess.in","r",stdin);
		freopen("chess.out","w",stdout);
	#endif
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) ord[i]=i;
	for (int i=1;i<=n;i++) {
		sum+=2*(m-i)-a[i];
		if (sum<0) {puts("no");return 0;}
	}
	for (int i=n+1;i<=m;i++) {
		sum+=2*(m-i);a[i]=min(a[i-1],sum);sum-=a[i];
	}
	if (sum!=0) {puts("no");return 0;}
	
	for (int i=1;i<=m;i++) {
		sort(ord+i,ord+m+1,comp);
		for (int j=i+1;j<=m;j++)
			ans[ord[i]][ord[j]]=1,
			ans[ord[j]][ord[i]]=1,
			a[ord[i]]--,a[ord[j]]--;
		for (int j=m;a[ord[i]]&&j>i;j--)
			ans[ord[i]][ord[j]]++,
			ans[ord[j]][ord[i]]--,
			a[ord[i]]--,a[ord[j]]++;
	}
	
	puts("yes");
	stand[0]='L';stand[1]='D';stand[2]='W'; 
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++)
	if (i!=j) str[i][j]=stand[ans[i][j]];
	else str[i][j]='X';
	for (int i=1;i<=m;i++)
		printf("%s\n",str[i]+1);
	return 0;
}