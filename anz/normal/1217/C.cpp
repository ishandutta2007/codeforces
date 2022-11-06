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

int frontZero[200001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	//freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--)
	{
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) frontZero[i] = 0;
		ll ans = 0;

		int curZero = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0') curZero++;
			else
			{
				frontZero[i] = curZero;
				curZero = 0;
			}
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0') continue;
			ll res = 1;
			int len = 1;
			ans++;
			for (int j = i + 1; j < s.size(); j++)
			{
				res *= 2;
				res += s[j] - '0';
				len++;

				if (res > s.size()) break;
				if (len + frontZero[i] >= res) ans++;
			}
		}

		cout << ans << "\n";
	}
}