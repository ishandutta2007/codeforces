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

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int sum = 0;
	int a[200001], b[200001], p[200002], s[200002];

	p[0] = 0;
	s[n + 1] = 0;

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		sum += b[i];

		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
		p[i] = max(p[i - 1], a[i]);

	for(int i = n; i >= 1; --i)
		s[i] = max(s[i + 1], a[i]);

	for(int i = 1; i <= n; ++i)
	{
		cout << (sum - b[i]) * max(p[i - 1], s[i + 1]) << " ";
	}
	cout << endl;

    return 0;
}