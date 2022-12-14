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

	int a[100000];

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int l;
	for(l = 0; l < n - 1; ++l)
		if(a[l] > a[l + 1])
			break;

	int r;
	for(r = n - 1; r > 0; --r)
		if(a[r - 1] > a[r])
			break;

	++r;

	if(l == n - 1)
	{
		cout << "yes" << endl << "1 1" << endl;
		return 0;
	}

	reverse(a + l, a + r);

	if(is_sorted(a, a + n))
		cout << "yes" << endl << l + 1 << " " << r << endl;
	else
		cout << "no" << endl;

    return 0;
}