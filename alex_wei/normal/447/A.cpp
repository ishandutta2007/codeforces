#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p,n,x,k[305];
int main()
{
	cin>>p>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(k[x%p])cout<<i,exit(0);
		k[x%p]=1;
	}
	cout<<-1;
	return 0;
}