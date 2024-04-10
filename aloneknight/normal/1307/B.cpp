#include<bits/stdc++.h>
using namespace std;
int n,d,a[100005];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);int ff=0;
		for(int i=1;i<=n;i++)if(a[i]==d)ff=1;
		if(ff)puts("1");
		else if(a[n]<d)printf("%d\n",(d+a[n]-1)/a[n]);
		else puts("2");
	}
	return 0;
}