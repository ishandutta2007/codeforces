#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501*1000)

int n,m;
string s,t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s>>t;
	bool flg=0;
	for(int i=0;i<s.size();i++)if(s[i]=='*')flg=1;
	if(!flg)
	{
		if(s==t)cout<<"YES\n";
		else cout<<"NO\n";
		return 0;
	}
	if(n>m+1)return cout<<"NO\n",0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='*')break;
		if(s[i]!=t[i])return cout<<"NO\n",0;
	}
	for(int i=(int)s.size()-1;i>=0;i--)
	{
		if(s[i]=='*')break;
		if(s[i]!=t[(int)t.size()-(int)s.size()+i])return cout<<"NO\n",0;
	}
	cout<<"YES\n";
	return 0;
}