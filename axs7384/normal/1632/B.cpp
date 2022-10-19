#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int p=1;
		while (p*2<n)
			p<<=1;
		for (int i=p-1;i>=0;--i)
			printf("%d ",i);
		for (int i=p;i<n;++i)
			printf("%d ",i);
		puts("");
	}
	return 0;
}