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

string s;
const ll MOD = 1e9 + 7;

ll dp[100001][2]; // 0:not 1:double
vector <int> v;

int main()
{
	dp[0][0] = 1, dp[0][1] = 0;
	dp[1][0] = 1, dp[1][1] = 0;

	for (int i = 2; i <= 100000; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
	}

	ll res = 1;
	cin >> s;

	char cl = '@';
	int cnt = 0;

	bool flag = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			flag = true;
			break;
		}
		if (s[i] == 'u')
		{
			if (cnt == 0) cl = 'u';
			if (cl != s[i])
			{
				v.push_back(cnt);
				cnt = 0;
				cl = 'u';
			}
			cnt++;
		}
		else if (s[i] == 'n')
		{
			if (cnt == 0) cl = 'n';
			if (cl != s[i])
			{
				v.push_back(cnt);
				cnt = 0;
				cl = 'n';
			}
			cnt++;
		}
		else
		{
			if (cnt)
			{
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	if (flag)
	{
		cout << 0;
		return 0;
	}

	if (cnt)
	{
		v.push_back(cnt);
		cnt = 0;
	}

	for (int it : v)
	{
		res *= (dp[it][0] + dp[it][1]) % MOD;
		res %= MOD;
	}

	cout << res;
}