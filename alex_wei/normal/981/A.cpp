#include<bits/stdc++.h>
using namespace std;
string s;
void read(){
	cin>>s;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])return;
	cout<<0,exit(0);
}
int main()
{
	read();
	for(int i=0;i<=s.size()/2;i++)
		if(s[i]!=s[s.size()-i-1])cout<<s.size(),exit(0);
	cout<<s.size()-1;
	return 0;
}