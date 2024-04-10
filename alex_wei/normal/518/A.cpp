#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
	cin>>s>>t;
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]<'z'){
			s[i]++;
			for(int j=i+1;j<s.size();j++)
				s[j]='a';
			break;
		}
	if(s<t)cout<<s;
	else cout<<"No such string";
	return 0;
}