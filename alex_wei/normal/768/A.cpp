#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=2,r=n-1;
	while(a[l]==a[l-1]&&l<=n)l++;
	while(a[r]==a[r+1]&&r)r--;
	cout<<max(0,r-l+1);
	return 0;
}