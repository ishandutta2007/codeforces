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

int HH,MM,tp;
char str[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("clock.in","r",stdin);
		freopen("clock.out","w",stdout);
	#endif
	scanf("%d %s",&tp,str+1);
	HH=10*(str[1]-'0')+(str[2]-'0');
	MM=10*(str[4]-'0')+(str[5]-'0');
	if (tp==24) {
		if (HH>=tp) HH%=10;
	}
	else {
		if (HH==0) HH=1;
		else if (HH>12) {
			if (HH%10<=2) HH=HH%10+10;
			else HH%=10;
		}
	}
	if (MM>=60) MM%=10;
	printf("%d%d:%d%d",HH/10,HH%10,MM/10,MM%10);
	return 0;
}