#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int gcd(int i,int j){return !j?i:gcd(j,i%j);}
int main()
{
	cin>>a>>b>>c>>d;
	if((d-b)%gcd(a,c))cout<<-1,exit(0);
	while(b!=d)b<d?b+=a:d+=c;
	cout<<b;
	return 0;
}