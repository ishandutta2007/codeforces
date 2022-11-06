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

	ll n, k; cin >> n >> k;
	string s; cin >> s;
	bool ok[26] = { 0, };
	for (int i = 0; i < k; i++)
	{
		char c; cin >> c;
		ok[c - 'a'] = true;
	}

	ll ans = 0;

	ll cur = 0;
	for (char c : s)
	{
		if (ok[c - 'a'])
		{
			cur++;
			continue;
		}

		ans += cur * (cur + 1) / 2;
		cur = 0;
	}

	ans += cur * (cur + 1) / 2;
	cout << ans;
}