#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for(int i=1;i<s.size()-1;i++)
		if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]&&s[i-1]!='.'&&s[i]!='.'&&s[i+1]!='.')
			cout<<"Yes",exit(0);
	cout<<"No";
	return 0;
}