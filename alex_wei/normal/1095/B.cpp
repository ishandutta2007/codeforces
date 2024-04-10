#include<bits/stdc++.h>
using namespace std;
int a[100002],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	cout<<min(a[n]-a[2],a[n-1]-a[1]);
	return 0;
}