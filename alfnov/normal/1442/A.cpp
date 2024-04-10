#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=1;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i]-a[i-1];
		int ans=0;
		for(int i=2;i<=n;i++)if(b[i]<0)ans+=abs(b[i]);
		if(b[1]>=ans)puts("YES");
		else puts("NO");
	}
	return 0;
}