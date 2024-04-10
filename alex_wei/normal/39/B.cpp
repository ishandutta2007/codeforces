#include<bits/stdc++.h>
using namespace std;
int n,a[102],p=1; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p+=(a[i]==p);
	cout<<p-1<<endl,p=1;
	for(int i=1;i<=n;i++)
		if(a[i]==p)p++,cout<<i+2000<<" ";
	return 0;
}