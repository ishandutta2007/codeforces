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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; string s;
	cin >> n >> s;

	int ans = 0;
	for (int i = 0; i < n / 2; i++)
	{
		char c1 = s[i * 2], c2 = s[i * 2 + 1];
		if (c1 == c2)
		{
			if (c1 == 'a') s[i * 2] = 'b';
			else s[i * 2] = 'a';
			ans++;
		}
	}

	cout << ans << "\n";
	cout << s;
}