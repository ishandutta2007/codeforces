#include<bits/stdc++.h>
using namespace std;
int n,a[4];
int main()
{
	scanf("%d%d%d%d",&n,&a[1],&a[2],&a[3]);
	--n;
	if (n==0)
	{
		cout<<0;
		return 0;
	}
	if (a[1]<=a[2]&&a[1]<=a[3])
	{
		cout<<n*a[1];
		return 0;
	}
	if (a[2]<=a[1]&&a[2]<=a[3])
	{
		cout<<n*a[2];
		return 0;
	}
	cout<<n*a[3]-a[3]+min(a[1],a[2]);
}