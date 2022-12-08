#include<bits/stdc++.h>

#define int long long
using namespace std;

int n,a[300000],l[300000],r[300000];

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=a[n+1]=-1;
	for(int i=1;i<=n;i++)
	{
		l[i]=i-1;
		while((a[i]|a[l[i]])==a[i])l[i]=l[l[i]];
	}
	for(int i=n;i>0;i--)
	{
		r[i]=i+1;
		while((a[i]|a[r[i]])==a[i]&&a[r[i]]<a[i])r[i]=r[r[i]];
	}
	int ans=n*(n+1)>>1;
	for(int i=1;i<=n;i++)ans-=(i-l[i])*(r[i]-i);
	cout<<ans<<endl;
}