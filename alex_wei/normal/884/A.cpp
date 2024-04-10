#include<bits/stdc++.h>
using namespace std;
int t,n,a;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a,a=86400-a;
		if(t>a)t-=a;
		else cout<<i,exit(0); 
	}
	return 0;
}