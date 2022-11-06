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

int n, m;
int memo[100001];
bool isCovered[100001];
pii ant[81];

int dp(int s)
{
	int& ret = memo[s];
	if (ret != -1) return ret;
	if (ret == m) return 0;
	if (isCovered[s + 1]) return ret = dp(s + 1);
	
	ret = m - s;
	for (int i = 0; i < n; i++)
	{
		if (ant[i].first > s)
		{
			int tmp = ant[i].first - s - 1;
			ret = min(ret, tmp + dp(min(m, ant[i].second + tmp)));
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(memo, -1, sizeof memo);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, s; cin >> x >> s;
		for (int i = max(1, x - s); i <= min(m, x + s); i++)
			isCovered[i] = true;
		ant[i] = { x - s, x + s };
	}

	cout << dp(0);
}