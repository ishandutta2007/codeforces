#include<bits/stdc++.h>
using namespace std;
int a,b,c;
string s;
int main()
{
	cin>>s;
	a=s.find('+'),b=s.find('=')-a-1,c=s.size()-s.find('=')-1;
	if(a+b==c)cout<<s,exit(0);
	if(a+b-c==2){
		if(a==1)cout<<s.substr(0,a)<<'+'<<s.substr(a+2,s.size()-a-2);
		else cout<<s.substr(1,s.size()-1);
		cout<<'|';
	}
	else if(c-a-b==2)cout<<'|'<<s.substr(0,s.size()-1);
	else cout<<"Impossible";
	return 0;
}