#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
string s;
int idx[N];
int ans[N];
int level[N];

int32_t main()
{
	IOS;
	cin >> n >> s;
	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			st.push(i);
		else
		{
			idx[i] = st.top();
			st.pop();
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] == ')')
		{
			cout << ans[idx[i]];
			level[ans[idx[i]]]--;
		}
		else
		{
			if(level[0] <= level[1])
			{
				cout << 0;
				level[0]++;
				ans[i] = 0;
			}
			else
			{
				cout << 1;
				level[1]++;
				ans[i] = 1;
			}
		}
	}
	return 0;
}