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
#include <limits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n, x;
ll a[300001];

ll dp[300001][2][2];

ll calc(int start, int multiplied, bool f)
{
	ll& ret = dp[start][multiplied][(int)f];
	if (ret != -1) return ret;

	ll curNum = 0;
	if (multiplied == 0) curNum = a[start];
	else curNum = a[start] * x;

	ll tcNum = curNum;

	if (start >= n - 1) return ret = curNum;

	ll t1 = 0, t2 = 0;
	if (multiplied)
	{
		t1 = calc(start + 1, 1, true);
		t2 = calc(start + 1, 0, false);

		ll tmp = max(t1, t2);
		curNum += tmp;
		return ret = max(tcNum, curNum);
	}
	else
	{
		if (f)
		{
			t1 = calc(start + 1, 1, true);
			t2 = calc(start + 1, 0, true);

			curNum += max(t1, t2);
		}
		else
		{
			curNum += calc(start + 1, 0, false);
		}
		return ret = max(tcNum, curNum);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%lld%lld", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	ll result = 0;

	for (int i = 0; i < n; i++)
	{
		result = max(result, calc(i, 0, 1));
		result = max(result, calc(i, 1, 1));
	}
	printf("%lld", result);
}