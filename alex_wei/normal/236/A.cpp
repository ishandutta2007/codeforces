#include<bits/stdc++.h>
using namespace std;
int c,p[128];
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		c+=p[s[i]]==0,p[s[i]]++;
	if(c%2)cout<<"IGNORE HIM!";
	else cout<<"CHAT WITH HER!";
    return 0;
}