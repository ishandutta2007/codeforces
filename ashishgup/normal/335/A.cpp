#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
string s;
string ans = "";
map<char, int> m;
 
bool check(int x)
{
	ans = "";
	set<pair<int, char> > st;
	for(auto it:m)
	{
		ans += it.first;
		if(it.second - x > 0)
			st.insert({it.second - x, it.first});
	}
	while(ans.size() < n)
	{
		if(!st.size())
			break;
		auto it = *st.begin();
		st.erase(it);
		ans += it.second;
		it.first -= x;
		if(it.first > 0)
			st.insert({it.first, it.second});
	}
	while(ans.size() < n)
		ans += 'a';
	return (st.size() == 0);
}
 
int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	check(lo);
	return lo;
}
 
int32_t main()
{
	IOS;
	cin >> s >> n;
	for(auto &it:s)
		m[it]++;
	if(n < m.size())
	{
		cout << -1;
		return 0;
	}
	int answer = binsearch(1, 1e5);
	cout << answer << endl;
	cout << ans;
	return 0;
}