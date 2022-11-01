#include <bits/stdc++.h>
using namespace std;

string s,p;
int main()
{
	cin>>s;
	s+='+';
	p+=s[0];
	for(int i=1;i<s.size();i++)
		if(!(s[i]=='/' && s[i-1]=='/'))	
			p+=s[i];
	for(int i=p.size()-2;i>0 && p[i]=='/';i--)
		p[i]='+';
	for(int i=0;p[i]!='+';i++)cout<<p[i];			
    return 0;
}