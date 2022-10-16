#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int gcd(int a,int b){return !b?a:gcd(b,a%b);} 
int main()
{
	cin>>a>>b>>c;
	if(c%gcd(a,b))cout<<"No",exit(0);
	for(int i=0;i<=c/a;i++)
		if((c-i*a)%b==0)
			cout<<"Yes",exit(0);
	cout<<"No";
	return 0;
}