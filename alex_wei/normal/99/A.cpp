#include<bits/stdc++.h>
using namespace std;
string s;
void print(int pos,bool pls)
{
	if(pos==-1){if(pls)cout<<1;return;}
	print(pos-1,s[pos]+pls>'9');
	if(s[pos]+pls>'9')cout<<0;
	else cout<<s[pos]+pls-'0';
}
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='.'){
			if(s[i-1]=='9')cout<<"GOTO Vasilisa.";
			else print(i-1,s[i+1]>'4');
			exit(0);
		}
	return 0;
}