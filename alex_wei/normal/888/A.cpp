#include<bits/stdc++.h>
using namespace std;
int n,a[1002],cnt;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<n;i++)
		if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))cnt++;
	cout<<cnt;
    return 0;
}