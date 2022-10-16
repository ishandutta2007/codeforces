#include<bits/stdc++.h>
using namespace std;
int n,a[105],b[1005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]++;
	for(int i=1;i<=1000;i++)
		if(b[i]>(n-1)/2+1)
			cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}