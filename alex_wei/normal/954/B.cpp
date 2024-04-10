#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=n/2;i>0;i--)
		if(s.substr(0,i)==s.substr(i,i))
			cout<<n-i+1,exit(0);
	cout<<n;
	return 0;
}