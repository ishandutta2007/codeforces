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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
vector <int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll tmp = 0;
	ll add = 1;
	while (tmp <= 1e9)
	{
		tmp += add;
		p.push_back(tmp);
		add++;
	}

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;

		vector <int> ans;
		while (n)
		{
			auto i = lower_bound(p.begin(), p.end(), n);
			if (i!=p.end() && (*i) == n)
			{
				ans.push_back(i - p.begin() + 1);
				break;
			}
			i--;
			n -= (*i);
			ans.push_back(i - p.begin() + 1);
		}

		reverse(ans.begin(), ans.end());

		int ptr = ans.size() - 1;
		while (ptr > 0)
		{
			cout << "1";
			for (int i = 0; i < ans[ptr] - ans[ptr - 1]; i++) cout << "3";
			ptr--;
		}
		cout << "1";
		for (int i = 0; i < ans[0] + 1; i++) cout << "3";
		cout << "7\n";
	}
}