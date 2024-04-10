#include<bits/stdc++.h>
using namespace std;
int n,x,c[102]; 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>c[i],c[i]*=(n-i+1);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(x<c[i])cout<<i-1,exit(0);
		x-=c[i];
	}
	cout<<n;
	return 0;
}