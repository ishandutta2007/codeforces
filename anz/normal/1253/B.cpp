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

int n;
set <int> cache;
set <int> s;
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	int cnt = 0;
	bool isValid = true;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		cnt++;
		if (a > 0)
		{
			if (s.find(a) != s.end())
			{
				isValid = false;
				break;
			}

			if (cache.find(a) != cache.end())
			{
				isValid = false;
				break;
			}

			s.insert(a);
			cache.insert(a);
		}
		else
		{
			a = -a;
			if (s.find(a) == s.end())
			{
				isValid = false;
				break;
			}
			s.erase(a);
			if (s.size() == 0)
			{
				ans.push_back(cnt);
				cache.clear();
				cnt = 0;
			}
		}
	}
	if (s.size() > 0) isValid = false;

	if(!isValid)
	{
		cout << "-1";
		return 0;
	}

	cout << ans.size() << '\n';
	for (auto it : ans) cout << it << ' ';
}