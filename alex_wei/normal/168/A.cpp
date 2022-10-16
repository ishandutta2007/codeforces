#include<bits/stdc++.h>
using namespace std;
double n,x,y;
int main()
{
	cin>>n>>x>>y;
	for(double i=0;i<1e9;i++)
		if(x+i>=n*y/100)
			cout<<i,exit(0);
	return 0;
}