/**
	inline void prlong long_hello()
	{
		string message = R"(Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.)";

		cout << message << endl;
	}
**/

/* _____ INCLUDES _____ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* _____ CODE _____ */

long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		a %= b;
		swap(a, b);
	}

	return a;
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

bool used_dfs[201];
bool in_cycle[201];
int a[201];

int dfs(int v)
{
	if(used_dfs[v] or in_cycle[v])
		return 0;

	used_dfs[v] = true;

	int ans = 0;

	if(a[v] != v)
		ans = max(dfs(a[v]) + 1, ans);

	return ans;
}

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int used[201];

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	long long ans = 1;

	for(int i = 1; i <= n; ++i)
	{
		memset(used, 0, sizeof(used));

		int cur = i;
		int len = 1;

		for(; used[cur] == 0; cur = a[cur], ++len)
		{
			used[cur] = len;
		}

		int ncur = a[cur];

		for(; ncur != cur; ncur = a[ncur])
			in_cycle[ncur] = true;

		ans = lcm(ans, len - used[cur]);
	}

	int minlen = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(not in_cycle[i])
		{
			memset(used_dfs, false, sizeof(used_dfs));
			minlen = max(minlen, dfs(i));
		}
	}

	ans = (((minlen - 1) / ans) + 1) * ans;

	cout << ans << endl;

    return 0;
}