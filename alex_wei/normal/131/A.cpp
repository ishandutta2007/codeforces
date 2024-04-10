#include<bits/stdc++.h>
using namespace std;
string s;
int pd=0;
int main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
		if(s[i]>'Z')cout<<s,exit(0);
	if(s[0]>'Z')s[0]-=32;
	else s[0]+=32;
	cout<<s[0];
	for(int i=1;i<s.size();i++)
		cout<<(char)(s[i]+32);
	return 0;
}