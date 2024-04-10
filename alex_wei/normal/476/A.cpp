#include<bits/stdc++.h>
using namespace std;
int n,m,c; 
int main()
{
	cin>>n>>m;
	c=(n+1)/2;
	for(int i=c;i<=n;i++)
		if(i%m==0)cout<<i,exit(0);
	cout<<-1;
	return 0;
}