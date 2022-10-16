#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	for(int i=0;i<=min(a,b);i++)
		if(a-i+b-i==c)
			cout<<i<<" "<<b-i<<" "<<a-i,exit(0);
	cout<<"Impossible";
	return 0; 
}