#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c,d,m,v; 
int main()
{
	cin>>a>>b>>c>>d;
	m=max(3*a/10,a-a/250*c);
	v=max(3*b/10,b-b/250*d);
	if(m>v)cout<<"Misha";
	else if(m==v)cout<<"Tie";
	else cout<<"Vasya";
	return 0;
}