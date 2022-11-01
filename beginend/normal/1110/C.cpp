#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int work(int x)
{
	int ans=1;
	for (int i=2;i*i<=x;i++)
		if (x%i==0) ans=std::max(ans,x/i);
	return ans;
}

int main()
{
	int q;scanf("%d",&q);
	while (q--)
	{
		int x;scanf("%d",&x);
		int t=1;
		while (t<=x) t<<=1;
		if (x!=t-1) printf("%d\n",t-1);
		else printf("%d\n",work(x)); 
	}
	return 0;
}