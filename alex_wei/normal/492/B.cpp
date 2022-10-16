#include<bits/stdc++.h>
using namespace std;
int n,l,a[1000005],ans; 
int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=max(a[1]*2,(l-a[n])*2);
	for(int i=2;i<=n;i++)
		ans=max(ans,a[i]-a[i-1]);
	printf("%.9lf",ans/2.0);
	return 0;
}