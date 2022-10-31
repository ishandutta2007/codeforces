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
const int maxn = 10005;

char str[maxn];
int n,p[maxn];
bool judge(char c) {
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("pattern.in","r",stdin);
		freopen("pattern.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	scanf("\n");
	for (int i=1;i<=n;i++) {
		gets(str+1);int len=strlen(str+1);
		int sum=0;
		for (int j=1;j<=len;j++)
		if (judge(str[j])) ++sum;
		if (sum!=p[i]) {puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}