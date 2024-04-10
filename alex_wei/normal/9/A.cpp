#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b;
	c=max(a,b);
	if(c==1)cout<<"1/1";
	else if(c==2)cout<<"5/6";
	else if(c==3)cout<<"2/3";
	else if(c==4)cout<<"1/2";
	else if(c==5)cout<<"1/3";
	else cout<<"1/6";
	return 0;
}