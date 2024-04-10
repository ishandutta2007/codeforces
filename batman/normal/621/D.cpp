#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld x,y,z,ans=-1;
string res;

int main()
{
	cin>>x>>y>>z;
	if(log(x)*pow(y,z)>ans)ans=log(x)*pow(y,z),res="x^y^z";
	if(log(x)*pow(z,y)>ans)ans=log(x)*pow(z,y),res="x^z^y";
	if(log(x)*y*z>ans)ans=log(x)*y*z,res="(x^y)^z";
	if(log(y)*pow(x,z)>ans)ans=log(y)*pow(x,z),res="y^x^z";
	if(log(y)*pow(z,x)>ans)ans=log(y)*pow(z,x),res="y^z^x";
	if(log(y)*x*z>ans)ans=log(y)*x*z,res="(y^x)^z";
	if(log(z)*pow(x,y)>ans)ans=log(z)*pow(x,y),res="z^x^y";
	if(log(z)*pow(y,x)>ans)ans=log(z)*pow(y,x),res="z^y^x";
	if(log(z)*x*y>ans)ans=log(z)*y*x,res="(z^x)^y";
	cout<<res;
    return 0;
}