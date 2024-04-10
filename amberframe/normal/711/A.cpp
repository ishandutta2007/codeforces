#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 1005;
char str[maxn][10];int n;
void print() {
	puts("YES");
	for (int i=1;i<=n;i++)
		printf("%s\n",str[i]+1);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("bus.in","r",stdin);
		freopen("bus.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for (int i=1;i<=n;i++) {
		if (str[i][1]=='O'&&str[i][2]=='O') {
			str[i][1]=str[i][2]='+';
			print();return 0;
		}
		if (str[i][4]=='O'&&str[i][5]=='O') {
			str[i][4]=str[i][5]='+';
			print();return 0;
		}
	}
	puts("NO");
	return 0;
}