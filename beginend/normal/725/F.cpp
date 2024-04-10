#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n;
LL w[N*2];

int main()
{
	scanf("%d",&n);
	LL ans=0;int tot=0;
	for (int i=1;i<=n;i++)
	{
		LL a,b,c,d,x,y;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a+b>=c+d)
		{
			w[++tot]=a+b;
			w[++tot]=c+d;
			ans+=a+c;
		}
		else
		{
			if (a>d) ans+=a-d;
			if (b>c) ans+=c-b;
		}
	}
	std::sort(w+1,w+tot+1);
	for (int i=1;i<=tot;i+=2) ans-=w[i];
	printf("%lld",ans);
	return 0;
}