#include<bits/stdc++.h>
using namespace std;
int n,a[105],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans+=a[i];
	for(int i=2;i<n;i++)
		if(!a[i]&&a[i-1]&&a[i+1])
			ans++;
	cout<<ans;
	return 0;
}