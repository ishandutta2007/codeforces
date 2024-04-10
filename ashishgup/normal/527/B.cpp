#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans = 0;
string s, t;
map<pair<char, char>, int> m, idx;
map<char, int> pos;

int32_t main()
{
	IOS;
	cin >> n >> s >> t;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != t[i])
		{
			m[{s[i], t[i]}]++;
			idx[{s[i], t[i]}] = i + 1;
			ans++;
			pos[s[i]] = i + 1;
		}
	}
	for(char a = 'a'; a <= 'z'; a++)
	{
		for(char b = a + 1; b <= 'z'; b++)
		{
			if(m[{a, b}] > 0 && m[{b, a}] > 0)
			{
				cout << ans - 2 << endl;
				cout << idx[{a, b}] << " " << idx[{b, a}] << endl;
				return 0;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] != t[i])
		{
			if(pos.find(t[i]) != pos.end())
			{
				cout << ans - 1 << endl;
				cout << i + 1 << " " << pos[t[i]] << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	cout << "-1 -1";
	return 0;
}