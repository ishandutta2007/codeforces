#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
string s;

int dp[501][501];

int solve(int start, int end)
{
	int &ret = dp[start][end];
	if (ret != -1) return ret;
	if (start > end) return ret = 0;
	if (start == end) return ret = 1;
	ret = 1 + solve(start + 1, end);
	for (int i = start + 1; i <= end; i++)
	{
		if (s[start] == s[i])
		{
			ret = min(ret, solve(start + 1, i - 1) + solve(i, end));
		}
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> s;
	cout << solve(0, n - 1);
}