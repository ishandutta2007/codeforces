#include<bits/stdc++.h>
using namespace std;
int n,k,a,b;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(i>k&&a!=b||a<1)cout<<i-1,exit(0);
		b=a;
	}
	cout<<n;
	return 0;
}