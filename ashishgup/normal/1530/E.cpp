#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e5 + 5;

int n;
string ans;

void work(string s)
{
	n = s.size();
	string cur = "";
	cur += s[0];
	reverse(s.begin(), s.end());
	ans = s;
	s.pop_back();
	map<char, int> m;
	for(auto &it:s)
		m[it]++;
	auto it = m.begin();
	int cnt = it -> second;
	if(cnt <= n / 2)
	{
		int sign = 0;
		char ch = it -> first;
		for(int i = 1; i <= n - 1; i++)
		{
			if(!sign && m[ch] > 0)
			{
				cur += ch;
				m[ch]--;
				sign ^= 1;
			}
			else
			{
				for(auto &it:m)
				{
					if(it.second > 0 && it.first != ch)
					{
						cur += it.first;
						it.second--;
						break;
					}
				}
				sign ^= 1;
			}
		}
		ans = min(ans, cur);
	}
	else
	{
		auto it = m.begin();
		it++;
		cur += it -> first;
		it -> second--;
		if(m.size() == 2)
		{
			while(it -> second)
			{
				cur += it -> first;
				it -> second--;
			}
			it--;
			while(it -> second)
			{
				cur += it -> first;
				it -> second--;
			}
			ans = min(ans, cur);
		}
		else
		{
			it--;
			while(it -> second)
			{
				cur += it -> first;
				it -> second--;
			}
			it++;
			it++;
			cur += it -> first;
			it -> second--;
			for(auto &it:m)
			{
				for(int i = 1; i <= it.second; i++)
					cur += it.first;
			}
			ans = min(ans, cur);
		}
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		map<char, int> m;
		for(auto &it:s)
			m[it]++;
		if(m.size() == 1)
		{
			cout << s << endl;
			continue;
		}
		int have = 0;
		char ch;
		for(auto &it:m)
		{
			if(it.second == 1)
			{
				have = 1;
				ch = it.first;
				break;
			}
		}
		if(have)
		{
			cout << ch;
			for(auto &it:s)
				if(it != ch)
					cout << it;
			cout << endl;
			continue;
		}
		work(s);
		cout << ans << endl;
	}
	return 0;
}