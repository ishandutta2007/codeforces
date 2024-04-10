#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]||b[i]-a[i]>=2)flag=0;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}