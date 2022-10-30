#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 200005;

char p[maxn],t[maxn];
int n,m,ord[maxn];

bool judge(int w)
{
	int pos=0;
	for (int i=1;i<=n&&pos<m;i++)
	if (ord[i]>w) {
		if (t[pos+1]==p[i]) ++pos;
	}
	return pos>=m;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	#endif
	scanf("%s %s",p+1,t+1);
	n=strlen(p+1);m=strlen(t+1);
	for (int x,i=1;i<=n;i++)
		scanf("%d",&x),ord[x]=i;
	int lb=0,rb=n+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (judge(mid)) lb=mid;
		else rb=mid;
	}
	printf("%d",lb);
	return 0;
}