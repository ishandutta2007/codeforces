#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=1;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)if(a[i]<=a[i+1])flag=0;
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}