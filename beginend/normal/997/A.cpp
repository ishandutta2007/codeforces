#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n;
LL x,y;
char s[N];

int main()
{
	scanf("%d%lld%lld",&n,&x,&y);
	scanf("%s",s+1);
	int now=0,cnt=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='0') now++;
		else if (now) cnt++,now=0;
	if (now) cnt++;
	if (!cnt) {puts("0");return 0;}
	LL ans=0;
	if (x<y) ans+=(LL)x*(cnt-1);
	else ans+=(LL)y*(cnt-1);
	ans+=y;
	printf("%lld",ans);
	return 0;
}