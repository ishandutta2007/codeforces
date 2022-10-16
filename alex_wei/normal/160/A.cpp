#include<bits/stdc++.h>
using namespace std;
int n,a[101],s,p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--){
		p+=a[i];
		if(p*2>s)cout<<n-i+1,exit(0);
	}
	return 0;
}