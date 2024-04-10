#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int n,a[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cout<<min(i>1?a[i]-a[i-1]:inf,i<n?a[i+1]-a[i]:inf)<<" "<<max(a[i]-a[1],a[n]-a[i])<<endl; 
	return 0;
}