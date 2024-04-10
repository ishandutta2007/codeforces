#include<bits/stdc++.h>
using namespace std;
int T,n,a[1005],b[1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
	}
	return 0;
}