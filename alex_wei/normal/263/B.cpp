#include<bits/stdc++.h>
using namespace std;
int n,k,a[51],b; 
int main()
{
	cin>>n>>k;
	if(k>n)cout<<-1,exit(0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-k+1]<<" "<<a[n-k+1];
	return 0;
}