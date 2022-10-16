#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,c[102];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i],c[i]%2?a++:b++;
	k=a<b;
	for(int i=1;i<=n;i++)if(c[i]%2==k)cout<<i,exit(0); 
	return 0;
}