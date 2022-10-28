#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int n;
int a[N];
int cache[N];
vector<int> g[N];

int dp(int idx)
{
	if(idx == n)
		return 0;
	int &ans = cache[idx];
	if(ans != -1)
		return ans;
	ans = 1e9;
	for(auto &it:g[idx])
		ans = min(ans, dp(it));
	ans += 1;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	stack<int> st;
	for(int i = n; i >= 1; i--)
	{
		while(st.size() && a[st.top()] < a[i])
			st.pop();
		if(st.size())
			g[i].push_back(st.top());
		st.push(i);
	}
	while(st.size())
		st.pop();
	for(int i = 1; i <= n; i++)
	{
		while(st.size() && a[st.top()] < a[i])
			st.pop();
		if(st.size())
			g[st.top()].push_back(i);
		st.push(i);
	}
	while(st.size())
		st.pop();
	for(int i = n; i >= 1; i--)
	{
		while(st.size() && a[st.top()] > a[i])
			st.pop();
		if(st.size())
			g[i].push_back(st.top());
		st.push(i);
	}
	while(st.size())
		st.pop();
	for(int i = 1; i <= n; i++)
	{
		while(st.size() && a[st.top()] > a[i])
			st.pop();
		if(st.size())
			g[st.top()].push_back(i);
		st.push(i);
	}
	while(st.size())
		st.pop();
	int ans = dp(1);
	cout << ans;
	return 0;
}