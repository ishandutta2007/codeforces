#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
LL tt[N];
LL l[N],tot=0;;
int main()
{
	scanf("%I64d",&n);
	LL a=0,b=0;
	LL sum=0;//1 
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&tt[u]);
		LL p=sqrt(tt[u]);
		if (p*p==tt[u]) 
		{
			a++;
			if (tt[u]!=0) sum++;
		}
		else 
		{
			b++;
			l[++tot]=min(tt[u]-p*p,(p+1)*(p+1)-tt[u]);
		}
	}
//	printf("%I64d %I64d\n",a,b);
	if (a==b) printf("0\n");
	else if (a>b)// 
	{
		LL need=(n/2)-b;
		if (need<=sum) printf("%I64d\n",need);
		else printf("%I64d\n",sum+(need-sum)*2);
	}
	else
	{
		sort(l+1,l+1+tot);
		LL need=(n/2)-a;
		LL ans=0;
		for (LL u=1;u<=need;u++)
			ans=ans+l[u];
		printf("%I64d\n",ans);
	}
	return 0;
}