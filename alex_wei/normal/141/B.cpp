#include<bits/stdc++.h>
using namespace std;
int a,x,y,c; 
int main()
{
	cin>>a>>y>>x;
	if(x%a==0)cout<<-1,exit(0);
	c=x/a;
	if(((c==0||c%2)&&abs(y)*2>=a)||(c%2==0&&c>0&&(y==0||abs(y)>=a)))cout<<-1;
	else if(c==0)cout<<1;
	else if(c%2)cout<<(c+1)/2*3-1;
	else cout<<c/2*3+(y>0);
	return 0; 
}