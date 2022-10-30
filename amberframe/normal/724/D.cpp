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

char str[maxn];
int bac[maxn],n,m;
bool check(char ch) {
	int las=0;
	for (int i=1;i<=n;i++) {
		if (str[i]<=ch) las=i;
		if (i-las>=m) return false;
	}
	return true;
}
void solve(char ch) {
	for (int i=1;i<=n;i++)
	if (str[i]<ch) bac[str[i]]++;
	int las=0,lasc=0;
	for (int i=1;i<=n;i++) {
		if (str[i]<=ch) {
			if (str[i]<ch) las=i;
			else lasc=i;
		}
		if (i-las>=m) {las=lasc;bac[ch]++;}
	}
	for (int i='a';i<='z';i++)
	for (int j=1;j<=bac[i];j++)
		printf("%c",i);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("subsequence.in","r",stdin);
		freopen("subsequence.out","w",stdout);
	#endif
	scanf("%d %s",&m,str+1);
	n=strlen(str+1);
	for (int i='a';i<='z';i++)
	if (check(i)) {solve(i);return 0;}
	return 0;
}