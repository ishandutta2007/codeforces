#include<bits/stdc++.h>
using namespace std;
string s;
int c;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if((s[i]<='9'&&s[i]>='0'&&s[i]%2)||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			c++;
	cout<<c;
	return 0;
}