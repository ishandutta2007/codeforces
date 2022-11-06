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

string s;

ll v[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;

	ll ans = 0;

	ll v_cnt = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'v' && s[i - 1] == 'v')
			v[i] = ++v_cnt;
		else
			v[i] = v_cnt;
	}

	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'o')
		{
			ans += v[i] * (v_cnt - v[i]);
		}

	cout << ans;
}