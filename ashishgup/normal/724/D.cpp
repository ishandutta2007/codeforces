#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, k;
string s;
set<int> idx[N];
 
int32_t main()
{
	IOS;
	cin >> k >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
		idx[s[i]].insert(i);
	int i = 0;
	string ans = "";
	while(i + k - 1 < n)
	{
		int l = i;
		int r = i + k - 1;
		for(char ch = 'a'; ch <= 'z'; ch++)
		{
			auto it = idx[ch].lower_bound(l);
			if(it != idx[ch].end() && *it <= r)
			{	
				ans += ch;
				auto it2 = idx[ch].upper_bound(r);
				it2--;
				i = *it2 + 1;
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	set<char> vis;
	for(char ch = 'a'; ch < ans.back(); ch++)
	{
		for(int i = 0; i < idx[ch].size(); i++)
			cout << ch;
	}
	for(int i = 0; i < ans.size(); i++)
	{
		if(ans[i] == ans.back())
			cout << ans[i];
	}
	return 0;
}