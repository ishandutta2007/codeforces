#include<bits/stdc++.h>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n,x,a,b;scanf("%d%d%d%d",&n,&x,&a,&b);
		if (a>b) std::swap(a,b);
		int w=std::min(n-b,x);
		b+=w;x-=w;
		w=std::min(x,a-1);
		a-=w;
		printf("%d\n",b-a);
	}
	return 0;
}