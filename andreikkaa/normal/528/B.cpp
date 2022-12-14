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

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.first + a.second < b.first + b.second;
}

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	pair<int, int> a[200000];

	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;

	sort(a, a + n, cmp);

	int ans = 1, l = 0;

	for(int i = 1; i < n; ++i)
	{
		if(a[i].first >= a[l].first)
		{
			if(a[i].first - a[i].second >= a[l].first + a[l].second)
			{
				++ans;
				l = i;
			}
		}
		else
		{
			if(a[l].first - a[l].second >= a[i].first + a[i].second)
			{
				++ans;
				l = i;
			}
		}

	}

	cout << ans << endl;

    return 0;
}