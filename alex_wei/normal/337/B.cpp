#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int a,b,c,d,e,f,g,h,i,j,k,l,m; 
int main()
{
	cin>>a>>b>>c>>d;
	e=a*c/gcd(a,c);
	f=b*e/a,g=d*e/c;
	if(g<=f){
		k=f-g,l=f;
		m=gcd(k,l);
		cout<<k/m<<"/"<<l/m;
		exit(0);
	}
	h=b*d/gcd(b,d);
	i=a*h/b,j=c*h/d;
	k=i-j,l=i;
	m=gcd(k,l);
	cout<<k/m<<"/"<<l/m; 
	return 0;
}