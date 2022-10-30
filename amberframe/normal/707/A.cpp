#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 105;
int n,m;
char s[maxn];bool flag=true;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("photos.in","r",stdin);
		freopen("photos.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		scanf("%s",s);
		if (*s!='B'&&*s!='W'&&*s!='G') flag=false;
	}
	if (flag) puts("#Black&White");
	else puts("#Color");
	return 0;
}