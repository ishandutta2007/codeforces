#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],p[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)scanf("%d",&c[i]);
		p[1]=a[1];
		for(int i=2;i<n;i++)
		{
			if(a[i]!=p[i-1])p[i]=a[i];
			else p[i]=c[i];
		}
		if(a[n]!=p[n-1]&&p[1]!=a[n])p[n]=a[n];
		else if(b[n]!=p[n-1]&&p[1]!=b[n])p[n]=b[n];
		else p[n]=c[n];
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		puts("");
	}
	return 0;
}