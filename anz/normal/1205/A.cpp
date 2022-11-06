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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int ans[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if (n % 2 == 0)
		cout << "NO";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			if (i % 2) ans[i] = i*2 + 1, ans[i + n] = i*2 + 2;
			else ans[i] = i * 2 + 2, ans[i + n] = i * 2 + 1;
		}
		for (int i = 0; i < 2 * n; i++) cout << ans[i] << ' ';
	}
}