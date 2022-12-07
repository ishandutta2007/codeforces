#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
char a[N],b[N];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	LL cnt0=0,cnt1=0;
	LL x=0,y=0;
	for (int u=1;u<=n;u++)
	{
		if (a[u]=='1'&&b[u]=='0') cnt1++;
		if (a[u]=='0'&&b[u]=='0') cnt0++;
		if (a[u]=='1') x++;
		if (a[u]=='0') y++;
	}
	LL ans=0;
	ans=ans+cnt0*x;
	ans=ans+cnt1*y;
	ans=ans-cnt1*cnt0;
	printf("%lld\n",ans);
	return 0;
}