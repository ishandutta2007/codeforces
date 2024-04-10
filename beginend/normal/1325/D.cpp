#include<bits/stdc++.h>

typedef long long LL;

LL u,v,bin[65];

int main()
{
	bin[0]=1;
	for (int i=1;i<=60;i++) bin[i]=bin[i-1]*2;
	scanf("%lld%lld",&u,&v);
	if (u==0&&v==0) {puts("0");return 0;}
	if (u>v||(v-u)%2==1) {puts("-1");return 0;}
	v-=u;
	if (!v) printf("%d\n%lld\n",1,u);
	else
	{
		bool flag=0;
		LL ans0=u,ans1=0;
		for (int i=1;i<=60;i++)
			if ((v&bin[i])&&!(u&bin[i-1])) ans0+=bin[i-1],ans1+=bin[i-1];
			else if (v&bin[i]) {flag=1;break;}
		if (!flag) printf("2\n%lld %lld\n",ans0,ans1);
		else printf("3\n%lld %lld %lld\n",u,v/2,v/2);
	}
	return 0;
}