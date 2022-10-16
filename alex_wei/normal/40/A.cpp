#include<bits/stdc++.h>
using namespace std;
double a,b,c;
int main()
{
	cin>>a>>b;
	c=sqrt(a*a+b*b);
	if(c==(int)c)cout<<"black",exit(0);
	if(((int)c%2&&a*b>0)||((int)c%2==0&&a*b<0))cout<<"white";
	else cout<<"black";
	return 0;
}