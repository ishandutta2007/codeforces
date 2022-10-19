#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	if(a[1]!=b[1])printf("No\n");
	else
	{
		for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
		for(int i=1;i<n;i++)b[i]=b[i+1]-b[i];
		sort(a+1,a+n);
		sort(b+1,b+n);
		int flag=1;
		for(int i=1;i<n;i++)if(a[i]!=b[i])flag=0;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}