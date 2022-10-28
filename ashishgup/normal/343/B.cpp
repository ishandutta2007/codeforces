#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		if(!st.empty() && st.top()==s[i])
		{
			st.pop();
			continue;
		}
		st.push(s[i]);
	}
	if(st.empty())
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}