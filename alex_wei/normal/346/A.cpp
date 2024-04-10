#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int n,d,a,mx;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,d=gcd(d,a),mx=max(mx,a);
	cout<<((mx/d-n)%2?"Alice":"Bob");
	return 0;
}