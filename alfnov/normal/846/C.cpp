#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long s[5005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	long long ans=LLONG_MIN;
	int a,b,c;
	for(int j=0;j<=n;j++)
	{
		long long h1=LLONG_MIN/2,h2=h1;
		for(int i=0;i<=j;i++)h1=max(h1,2*s[i]-s[j]);
		for(int k=j;k<=n;k++)h2=max(h2,2*s[k]-s[j]-s[n]);
		ans=max(ans,h1+h2);
		if(ans==h1+h2)b=j;
	}
	long long h1=LLONG_MIN/2,h2=h1;
	for(int i=0;i<=b;i++)
	{
		h1=max(h1,2*s[i]-s[b]);
		if(h1==2*s[i]-s[b])a=i; 
	}
	for(int i=b;i<=n;i++)
	{
		h2=max(h2,2*s[i]-s[b]-s[n]);
		if(h2==2*s[i]-s[b]-s[n])c=i;
	}
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}