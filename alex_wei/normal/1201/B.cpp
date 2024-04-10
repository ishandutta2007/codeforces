#include<bits/stdc++.h>
using namespace std;
long long a[100002],n,s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	if(s%2)cout<<"NO",exit(0);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		a[i]+=a[i-1];
	if(a[n-1]>=a[n])cout<<"YES";
	else cout<<"NO";
	return 0;
}