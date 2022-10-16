#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A')n++;
		else if(s[i]=='1')n+=10;
		else n+=s[i]-'0';
	}
	cout<<n;
	return 0;
}