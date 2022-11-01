#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int d,e,n;

int main()
{
	scanf("%d%d%d",&n,&d,&e);
	e=e*5;
	int ans=n;
	for (int i=0;i*d<=n;i++) ans=std::min(ans,(n-d*i)%e);
	printf("%d\n",ans);
	return 0;
}