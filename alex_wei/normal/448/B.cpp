#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[26],b[26];
int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)a[s[i]-'a']++;
	for(int i=0;i<t.size();i++)b[t[i]-'a']++;
	for(int i=0;i<26;i++)
		if(b[i]>a[i])
			puts("need tree"),exit(0);
	if(s.size()==t.size())puts("array"),exit(0);
	int pos=0;
	for(int i=0;i<s.size();i++)
		if(pos<t.size()&&s[i]==t[pos])
			pos++;
	if(pos==t.size())puts("automaton");
	else puts("both");
    return 0;
}