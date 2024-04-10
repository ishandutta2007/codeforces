#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;

stack <char> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!st.size())
		{
			st.push(s[i]);
			continue;
		}
		if(st.top()==s[i])
			st.pop();
		else
			st.push(s[i]);	
	}
	if(st.size())
		cout<<"NO";
	else
		cout<<"YES";	
	return 0;
}