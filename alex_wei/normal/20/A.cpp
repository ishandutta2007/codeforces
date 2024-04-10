#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	int i=s.size()-1;
	for(;i>=0&&s[i]=='/';i--);
	cout<<'/';
	for(int j=1;j<=i;j++){
		if(s[j]=='/'&&s[j-1]=='/')continue;
		cout<<s[j];
	}
	return 0;
}