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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll arr[12] = { 1,2,4,8,16,32,64,128,256,512,1024,2048 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		map <ll, int> mp;
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			ll t; cin >> t;
			mp[t]++;
		}

		for (int i = 0; i < 11; i++)
		{
			int cnt = mp[arr[i]];
			mp[arr[i + 1]] += cnt / 2;
		}

		if (mp[2048] > 0) cout << "YES\n";
		else cout << "NO\n";
	}
}