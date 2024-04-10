#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		if(a[i-2]>a[i]-a[i-1]&&a[i-2]+a[i-1]>a[i])
			cout<<"YES",exit(0);
	cout<<"NO";
    return 0;
}