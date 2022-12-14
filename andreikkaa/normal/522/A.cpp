/**
	inline void print_hello()
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

map<string, vector<string>> g;

int dfs(string s)
{
	int ans = 0;

	for(auto i : g[s])
		ans = max(ans, dfs(i));

	return ans + 1;
}

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string s, t, u;
		cin >> s >> t >> u;

		transform(s.begin(), s.end(), s.begin(), ::tolower);
		transform(u.begin(), u.end(), u.begin(), ::tolower);

		g[u].push_back(s);
	}

	cout << dfs("polycarp") << endl;

    return 0;
}