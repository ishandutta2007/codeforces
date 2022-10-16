#include<bits/stdc++.h>
using namespace std;
double a,b,c,n; 
int main()
{
	cin>>a>>b>>n;
	for(double i=-abs(b);i<=abs(b);i++)
		if(a*pow(i,n)==b)cout<<i,exit(0);
	cout<<"No solution";
	return 0;
}