#include<bits/stdc++.h>
using namespace std;
int a[55];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int flag=0;
		for(int i=1;i<n;i++)if(a[i+1]-a[i]>1)flag=1;
		if(!flag)puts("YES");
		else puts("NO");
	}
	return 0;
}