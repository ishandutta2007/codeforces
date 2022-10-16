#include<bits/stdc++.h>
using namespace std;
int n,a[1010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n]<<" ";
	for(int i=2;i<n;i++)cout<<a[i]<<" ";
	cout<<a[1];
    return 0;
}