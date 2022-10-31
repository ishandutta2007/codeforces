#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 200005;

char str[maxn];
int n,K,pos,tj,tk;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("grade.in","r",stdin);
		freopen("grade.out","w",stdout);
	#endif
	scanf("%d %d",&n,&K);scanf("%s",str+1);
	pos=1;while (str[pos]!='.') ++pos;
	tj=pos+1;while (tj<=n&&str[tj]<'5') ++tj;
	if (tj>n||K==0) {for (int i=1;i<=n;i++) printf("%c",str[i]);return 0;}
	tk=tj-1;while (tk>pos&&str[tk]=='4') --tk;++tk;
	int las=max(tj-K,tk-1);str[las]++;
	while (las>pos&&str[las]>'9') {--las;str[las]++;}
	if (las==pos) {
		--las;str[las]++;int tl=las;
		while (tl&&str[tl]>'9') {
			str[tl]='0';tl--;str[tl]++;
		}
		if (!tl) printf("1");
	}
	for (int i=1;i<=las;i++) printf("%c",str[i]);
	return 0;
}