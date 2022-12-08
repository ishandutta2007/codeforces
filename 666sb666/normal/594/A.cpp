#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=1e9;
	for(int i=1;i<=n/2;i++)ans=min(ans,a[i+n/2]-a[i]);
	printf("%d\n",ans);
	return 0;
}