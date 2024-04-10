#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int cnt=0;
	string s;
	cin>>s;
	stack<char> st;
	for(auto &ch:s)
	{
		if(st.size() && ch==st.top())
		{
			cnt++;
			st.pop();
		}
		else
			st.push(ch);
	}
	if(cnt%2)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}