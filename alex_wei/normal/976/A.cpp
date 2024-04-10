#include<bits/stdc++.h>
using namespace std;
int n;
string s; 
int main()
{
	cin>>n>>s;
	if(n==1&&s[0]=='0')cout<<0,exit(0);
	cout<<1;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')cout<<0;
	return 0;
}