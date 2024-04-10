#include<bits/stdc++.h>
using namespace std;
int n,sum,t=100,k,ct;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k,sum+=k;
		if(k%2)ct++,t=min(t,k);
	}
	if(ct==0)cout<<0,exit(0);
	if(ct%2==0)sum-=t;
	cout<<sum;
	return 0;
}