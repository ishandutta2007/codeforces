#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, perfect=0;
string a[N];
map<int, int> pos, neg;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int sz=a[i].size();
		int idx=0, cnt=0;
		stack<char> st;
		while(idx<sz)
		{
			char ch=a[i][idx];
			if(ch=='(')
				st.push(ch);
			else
			{
				if(st.size() && st.top()=='(')
					st.pop();
				else
					st.push(ch);
			}
			idx++;
		}
		int open=0, close=0;
		while(st.size())
		{
			char ch=st.top();
			st.pop();
			open+=(ch=='(');
			close+=(ch==')');
		}
		if(open==0 && close==0)
			perfect++;
		else if(open==0 && close>0)
			pos[close]++;
		else if(open>0 && close==0)
			neg[open]++;
	}
	int ans=perfect/2;
	for(auto &it:pos)
	{
		if(neg.find(it.first)!=neg.end())
			ans+=min(it.second, neg[it.first]);
	}
	cout<<ans;
	return 0;
}