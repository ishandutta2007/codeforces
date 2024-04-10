#include<bits/stdc++.h>
using namespace std;
int n,a,t[3003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,t[a]=1;
	for(int i=1;i<3002;i++)
		if(!t[i])cout<<i,exit(0);
	return 0;
}