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

int n, k, p, x, y;
int a[1000];

void solve_le()
{
    int c_l = 0, c_eg = 0, sum = 0;

    for(int i = 0; i < k; ++i)
	{
		if(a[i] < y)
			++c_l;
		else
			++c_eg;

		sum += a[i];
	}

	sum += ((n / 2) - c_eg) * y;

	sum += ((n / 2) - c_l);

	if(sum <= x)
	{
		for(int i = 0; i < ((n / 2) - c_eg); ++i)
			cout << y << " ";

		for(int i = 0; i < ((n / 2) - c_l); ++i)
			cout << 1 << " ";

		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

void solve_g()
{
	sort(a, a + k);

	int ind = 0;

	for(int i = 0; i < k; ++i, ++ind)
		if(a[i] >= y)
			break;

	if(ind > n / 2)
	{
		cout << -1 << endl;
		return;
	}

	int c_l = 0, c_eg = 0, sum = 0;

    for(int i = 0; i < k; ++i)
	{
		if(a[i] < y)
		{
			if(c_l < n / 2)
				++c_l;
			else
				++c_eg;
		}
		else
		{
			if(c_eg <= n / 2)
				++c_eg;
			else
				++c_l;
		}

		sum += a[i];
	}

	sum += ((n / 2) - c_eg + 1) * y;

	sum += ((n / 2) - c_l);

	if(sum <= x)
	{
		for(int i = 0; i < ((n / 2) - c_eg + 1); ++i)
			cout << y << " ";

		for(int i = 0; i < ((n / 2) - c_l); ++i)
			cout << 1 << " ";

		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}




}

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);


	cin >> n >> k >> p >> x >> y;

	for(int i = 0; i < k; ++i)
		cin >> a[i];

	/*if(k <= n / 2)
		solve_le();
	else*/
		solve_g();

    return 0;
}