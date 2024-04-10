#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=2;i<n;i++)if(a[i]<a[i-1]+a[i-2])return cout<<"YES",0;
	cout<<"NO";
	return 0;
}