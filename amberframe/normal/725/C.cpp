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
char ans[2][maxn];
int id[2][maxn];
int A,B;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("word.in","r",stdin);
		freopen("word.out","w",stdout);
	#endif
	scanf("%s",str+1);
	for (int i=1;i<=27;i++)
	for (int j=i+1;j<=27;j++)
		if (str[i]==str[j]) {A=i;B=j;break;}
	if (A+1==B) {puts("Impossible");return 0;}

	for (int i=B;i<27;i++) str[i]=str[i+1];
	for (int i=1;i<=26;i++) str[i+52]=str[i+26]=str[i];

	int cnt=0;
	for (int j=1;j<=13;j++) id[1][j]=++cnt;
	for (int j=13;j>=1;j--) id[2][j]=++cnt;
	int t=(B-A-1)/2;
	for (int i=1;i<=2;i++) {
		for (int j=1;j<=13;j++) {
			char c=str[id[i][j]-id[1][13-t]+A+26];
			printf("%c",c);
		}
		puts("");
	}
	return 0;
}