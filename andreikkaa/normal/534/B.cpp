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

	int v1, v2, t, d;

	cin >> v1 >> v2 >> t >> d;

	int pr[100];
	int su[100];

	pr[0] = v1;

	for(int i = 1; i < t; ++i)
		pr[i] = pr[i - 1] + d;

	su[t - 1] = v2;

	for(int i = t - 2; i >= 0; --i)
		su[i] = su[i + 1] + d;

	int ans = 0;

	for(int i = 0; i < t; ++i)
		ans += min(pr[i], su[i]);

	cout << ans << endl;

    return 0;
}