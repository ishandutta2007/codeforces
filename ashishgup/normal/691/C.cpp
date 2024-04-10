#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;
string ans="";

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	int dig=-1, idx=-1;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='1' && s[i]<='9')
		{
			dig=s[i]-'0';
			idx=i;
			ans+=s[i];
			break;
		}
	}
	int dot=n;
	for(int i=0;i<n;i++)
		if(s[i]=='.')
			dot=i;
	while(s.size() && s.back()=='0'||s.back()=='.')
		s.pop_back();
	int decimal=0;
	for(int i=idx+1;i<s.size();i++)
	{
	    if(!(s[i]>='0'&&s[i]<='9'))
	        continue;
		if(decimal==0)
		{
			ans+='.';
			decimal=1;
		}
		ans+=s[i];
	}
	if((dot-idx-1)>0)
	{
		ans+='E';
		ans+=to_string(dot-idx-1);
	}
	else if((dot-idx-1)<0)
	{
		ans+='E';
		ans+=to_string(dot-idx);
	}
	cout<<ans;
	return 0;
}