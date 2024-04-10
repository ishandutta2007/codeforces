#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1)
	{
		cout<<1<<" "<<1<<endl<<-a[1]<<endl;
		cout<<1<<" "<<1<<endl<<0<<endl;
		cout<<1<<" "<<1<<endl<<0<<endl;
		return 0;
	}
	cout<<1<<" "<<n-1<<endl;
	for(int i=1;i<n;i++)
	{
		printf("%lld ",1ll*(n-1)*(a[i]%n));
		a[i]+=1ll*(n-1)*(a[i]%n);
	}
	cout<<endl;
	cout<<n<<" "<<n<<endl;
	cout<<-1ll*(a[n]%n)<<endl;
	a[n]-=a[n]%n;
	cout<<1<<" "<<n<<endl;
	for(int i=1;i<=n;i++)printf("%lld ",-a[i]);
	return 0;
}