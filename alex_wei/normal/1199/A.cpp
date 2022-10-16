#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[100002];
int main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int pd=1;
		for(int j=max(1,i-x);j<=min(n,i+y);j++)
			if(a[j]<a[i])pd=0;
		if(pd)cout<<i,exit(0);
	}
	return 0;
}