#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,a[102];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=gcd(a[i],a[i-1]);
	cout<<a[n]*n; 
	return 0;
}