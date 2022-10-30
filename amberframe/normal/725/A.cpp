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
const int maxn = 200005;

char str[maxn];int n,ans;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("ball.in","r",stdin);
		freopen("ball.out","w",stdout);
	#endif
	scanf("%d %s",&n,str+1);
	int i=1,j=n;
	while (i<=n&&str[i]=='<') ++i;
	while (j>=1&&str[j]=='>') --j;
	printf("%d",n-max(0,j-i+1));
	return 0;
}