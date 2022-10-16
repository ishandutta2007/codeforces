#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200002],ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n/2+2;i<=n;i++){
		if(ans+(a[i]-a[i-1])*(i-n/2-1)>k)
			cout<<a[i-1]+(k-ans)/(i-n/2-1),exit(0);
		ans+=(a[i]-a[i-1])*(i-n/2-1);
	}
	cout<<a[n]+(k-ans)/(n-n/2);
	return 0;
}