#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='.')cout<<0;
		if(i<s.size()-1&&s[i]=='-'&&s[i+1]=='.')cout<<1,i++;
		if(i<s.size()-1&&s[i]=='-'&&s[i+1]=='-')cout<<2,i++;
	}
    return 0;
}