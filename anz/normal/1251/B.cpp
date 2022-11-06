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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n;  cin >> n;

		bool hasOdd = false;
		int cnt[2] = { 0,0 };

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (s.size() % 2) hasOdd = true;
			for (char c : s)
				cnt[c - '0']++;
		}

		if (!hasOdd && cnt[0] % 2) cout << n - 1 << "\n";
		else cout << n << "\n";
	}
}