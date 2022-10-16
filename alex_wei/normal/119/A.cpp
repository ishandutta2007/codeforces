#include<bits/stdc++.h>
using namespace std;
int a,b,n,k;
int gcd(int x,int y){
	if(y==0)return x;
	else return gcd(y,x%y);
}
int main()
{
	cin>>a>>b>>n;
	while(n){
		if(!k)n-=gcd(n,a);
		else n-=gcd(n,b);
		if(!n)cout<<k;
		k=!k;
	}
	return 0;
}