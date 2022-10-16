#include<bits/stdc++.h>
using namespace std;
string s,t;
int pos=0; 
int main()
{
	cin>>s>>t;
	for(int i=0;i<t.size()&&pos<s.size();i++)
		if(t[i]==s[pos])pos++;
	cout<<pos+1;
	return 0;
}