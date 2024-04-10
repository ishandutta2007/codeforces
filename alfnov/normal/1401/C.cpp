#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,mn=INT_MAX;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i],mn=min(mn,a[i]);
		sort(b+1,b+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)if(b[i]!=a[i]&&b[i]%mn)
		{
			puts("NO");
			flag=0;
			break;
		}
		if(flag)puts("YES");
	}
	return 0;
}