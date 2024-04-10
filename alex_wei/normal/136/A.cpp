#include<bits/stdc++.h>
using namespace std;
int n,c[101],t; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t,c[t]=i;
	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	return 0;
}