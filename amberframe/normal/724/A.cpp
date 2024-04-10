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

char a[maxn],b[maxn];
int day(char *str) {
	if (*str=='m') return 0;
	if (*str=='w') return 2;
	if (*str=='t') {
		if (str[1]=='u') return 1;
		if (str[1]=='h') return 3;
	}
	if (*str=='f') return 4;
	if (*str=='s') {
		if (str[1]=='a') return 5;
		if (str[1]=='u') return 6;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("calendar.in","r",stdin);
		freopen("calendar.out","w",stdout);
	#endif
	scanf("%s %s",a,b);
	int d=(day(b)-day(a)+7)%7;
	if (d==0||d==2||d==3) puts("YES");
	else puts("NO");
	return 0;
}