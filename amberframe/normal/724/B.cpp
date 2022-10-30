#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 1005;

char a[maxn][maxn];int n,m;
bool judge() {
	for (int i=1;i<=n;i++) {
		int cnt=0;
		for (int j=1;j<=m;j++)
			cnt+=(a[i][j]!=j);
		if (cnt>2) return false;
	}
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("sort.in","r",stdin);
		freopen("sort.out","w",stdout);
	#endif

	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) {
		for (int k=1;k<=n;k++)
			swap(a[k][i],a[k][j]);
		if (judge()) {puts("YES");return 0;}
		for (int k=1;k<=n;k++)
			swap(a[k][i],a[k][j]);
	}
	puts("NO");
	return 0;
}