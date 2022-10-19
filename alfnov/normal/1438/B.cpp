#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int flag=0;
		for(int i=2;i<=n;i++)if(a[i]==a[i-1])
		{
			flag=1;
			puts("YES");
			break;
		}
		if(!flag)puts("NO");
	}
	return 0;
}