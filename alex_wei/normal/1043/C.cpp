#include<bits/stdc++.h>
using namespace std;
string s;
int op[1002];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i<s.size()-1&&s[i]!=s[i+1])reverse(s.begin(),s.begin()+i+1),cout<<"1 ";
		else if(i==s.size()-1&&s[i]=='a')cout<<"1 ";
		else cout<<"0 ";
	}
	return 0;
}