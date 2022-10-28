#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int odd = 0;
map<char, int> m;

void remove(char ch)
{
	odd -= m[ch] %  2;
	m[ch]--;
	odd += m[ch] % 2;
}

void add(char ch)
{
	odd -= m[ch] % 2;
	m[ch]++;
	odd += m[ch] % 2;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		m.clear();
		string s;
		cin >> s;
		int n = s.size();
		for(int i = 0; i < n; i++)
			m[s[i]]++;
		if(m['0'] == n - 1 && m['1'] == 1)
		{
			for(int i = 0; i < n - 2; i++)
				cout << 9;
			cout << endl;
			continue;
		}
		if(m['0'] == n - 2 && s[0] == '1' && s.back() == '1')
		{
			for(int i = 0; i < n - 2; i++)
				cout << 9;
			cout << endl;
			continue;
		}
		odd = 0;
		for(auto &it:m)
			odd += it.second % 2;
		bool printed = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			remove(s[i]);
			for(char ch = s[i] - 1; ch >= '0'; ch--)
			{
				if(printed)
					break;
				add(ch);
				if(n - 1 - i >= odd)
				{
					for(int j = 0; j < i; j++)
						cout << s[j];
					cout << ch;
					for(int j = 0; j < n - 1 - i - odd; j++)
						cout << 9;
					vector<char> v;
					for(auto &it:m)
						if(it.second%2)
							v.push_back(it.first);
					reverse(v.begin(), v.end());
					for(auto &it:v)
						cout << it;
					cout << endl;
					printed = 1;
					break;
				}
				remove(ch);
			}
		}
	}
	return 0;
}