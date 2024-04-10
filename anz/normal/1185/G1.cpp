#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

const int MOD = 1000000007;
int n, T;
vector <pii> songs;
ll dp[15][(1 << 15) + 101];

int c;

ll solve(int start, int st, int len)
{
	ll& ret = dp[start][st];
	if (ret != -1) return ret;
	ret = 0;

	if (len == T) return ret = 1;

	for (int i = 0; i < n; i++)
	{
		if ((st & (1 << i)) == 0)
		{
			pii song = songs[i];
			if (song.second != songs[start].second)
			{
				if (len + song.first <= T)
					ret += solve(i, st | (1 << i), len + song.first), ret %= MOD;
			}
		}
	}

	return ret;
}

int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
	{
		int t, g;
		scanf("%d%d", &t, &g);
		songs.push_back({ t,g });
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		c = songs[i].second;
		ans += solve(i, 1 << i, songs[i].first);
		ans %= MOD;
	}

	printf("%lld", ans);
}