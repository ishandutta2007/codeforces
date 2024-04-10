#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> s;
	n = s.size();
	int ans = 0;
	map<char, int> m;
	map<string, int> m2;
	for(auto &it:s)
	{
		for(char ch = 'a'; ch <= 'z'; ch++)
		{
			string cur = "";
			cur += ch;
			cur += it;
			m2[cur] += m[ch];
			ans = max(ans, m2[cur]);
		}
		m[it]++;
		ans = max(ans, m[it]);
	}
	cout << ans;
	return 0;
}