#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,a[N],ans;

int main()
{
    ios_base::sync_with_stdio();cin.tie();cout.tie(0);
    cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll sum=a[n-1];
	for(int i=n-2;i>=0;i--)
		ans+=sum-(n-i-1)*a[i],sum+=a[i];
	ans*=2;
	ans+=sum;
	cout<<ans/__gcd(ans,n)<<" "<<n/__gcd(ans,n);	
    return 0;
}