#include<bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]!=b[i])cout<<"rated",exit(0);
	}
	for(int i=1;i<n;i++)
		if(a[i]<a[i+1])
			cout<<"unrated",exit(0);
	cout<<"maybe";
	return 0;
}