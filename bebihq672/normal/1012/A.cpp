#include<bits/stdc++.h>
using namespace std;
int a[202020];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	long long ans=1ll*(a[n]-a[1])*(a[2*n]-a[n+1]);
	for(int i=2;i<=n;i++)
		ans=min(ans,1ll*(a[n+i-1]-a[i])*(a[2*n]-a[1]));
	printf("%I64d\n",ans);
	return 0;
}