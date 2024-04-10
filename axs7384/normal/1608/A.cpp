#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=2;i<=n+1;++i)
			printf("%d ",i);
		puts("");
	}
	return 0;
}