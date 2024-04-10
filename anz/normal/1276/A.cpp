#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;

		vector<int> ans;
		char last[2];
		last[0] = '#', last[1] = '#';
		for (int i = 0; i < s.size(); i++)
		{
			if (last[0] == 'o' && last[1] == 'n' && s[i] == 'e')
			{
				last[1] = s[i];
				ans.push_back(i);
			}
			else if (last[0] == 't' && last[1] == 'w' && s[i] == 'o')
			{
				if (i + 2 < s.size() && s[i + 1] == 'n' && s[i + 2] == 'e')
				{
					ans.push_back(i + 1);
				}
				else
				{
					last[1] = s[i];
					ans.push_back(i);
				}
			}
			else
			{
				last[0] = last[1];
				last[1] = s[i];
			}
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}