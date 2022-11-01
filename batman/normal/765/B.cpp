#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N ((ll)301*1000)

string s;
ll now=0;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'a'==now){now++;continue;}
		if(s[i]-'a'<now)continue;
		return cout<<"NO\n",0;
	}
	cout<<"YES\n";
	return 0;
}