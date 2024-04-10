#include<bits/stdc++.h>
using namespace std;
int n,s,p;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	cin>>n;
	for(int i=2;i<n;i++){
		int r=n;
		while(r)s+=r%i,r/=i;
	}
	n-=2;
	cout<<s/gcd(s,n)<<'/'<<n/gcd(s,n);
	return 0;
}