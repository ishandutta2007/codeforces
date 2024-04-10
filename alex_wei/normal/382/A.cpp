#include<bits/stdc++.h>
using namespace std;
string s,t;
int pos,b,l,c;
int main()
{
	cin>>s>>t,l=t.size();
	pos=s.find('|');
	b=s.size()-pos-1,c=abs(pos-b);
	if(abs(pos-b)>t.size()||abs(pos-b)%2!=t.size()%2)cout<<"Impossible";
	else if(pos>b)cout<<t.substr(0,(l-c)/2)<<s<<t.substr((l-c)/2,(l+c)/2);
	else cout<<t.substr(0,(l+c)/2)<<s<<t.substr((l+c)/2,(l-c)/2);
	return 0;
}