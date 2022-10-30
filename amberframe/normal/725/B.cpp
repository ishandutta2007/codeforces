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
LL n,ans;char ch;int len;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("plane.in","r",stdin);
		freopen("plane.out","w",stdout);
	#endif
	scanf("%s",str+1);
	len=strlen(str+1);
	for (int i=1;i<len;i++)
		n=n*10ll+str[i]-'0';
	ch=str[len];
	LL m=(n-1)/4;n-=m*4;ans=m*12ll;ans+=4*m;
	if (n==2||n==4) ans+=7;
	if (ch>='d') ans+='f'-ch+1;
	else ans+=3+ch-'a'+1;
	printf("%lld",ans);
	return 0;
}