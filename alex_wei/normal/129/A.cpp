#include<bits/stdc++.h>
using namespace std;
int a[102],s,n,t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	for(int i=1;i<=n;i++)t+=(s%2==a[i]%2);
	cout<<t;
	return 0;
}