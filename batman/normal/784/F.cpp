#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)7001*1000)

ll n,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<(ll)2e9;i++)a[100]=a[100]+i;
	for(int i=0;i<1000;i++)
		for(int i=0;i<n-1;i++)
			if(a[i]>a[i+1])
			{
				ll tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
	for(int i=0;i<n-1;i++)cout<<a[i]<<" ";
	cout<<a[n-1]<<"\n";
	return 0;
}