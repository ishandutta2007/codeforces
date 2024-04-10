#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int f[5];
int ans[5];
map<char, int> m;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	m['R']=1;
	m['B']=2;
	m['Y']=3;
	m['G']=4;
	for(int i=0;i<s.size();i++)
		if(s[i]=='!')
			f[i%4]++;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='!')
			continue;
		ans[m[s[i]]]=f[i%4];
	}
	for(int i=1;i<=4;i++)
		cout<<ans[i]<<" ";
	return 0;
}