#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int p,ans;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')p++;
		else if(p)p--,ans+=2;
	cout<<ans;
    return 0;
}