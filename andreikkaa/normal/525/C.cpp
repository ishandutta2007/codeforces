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

const pair<bool, long long> BAD = {false, 0};

pair<bool, long long> go(long long a, long long b, long long c, long long d)
{
    if(a - b > 1)
        return BAD;
    if(a - b == 1)
        --a;

    if(c - d > 1)
        return BAD;
    if(c - d == 1)
        --c;

    return {true, a * c};
}

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int a[(int)1e6 + 1];
    memset(a, 0, sizeof a);

    long long ans = 0;

    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        ++a[t];
    }

    for(int i = 1e6; i > 0; --i)
    {
        if(a[i] % 2 == 1)
        {
            --a[i];
            if(a[i - 1] > 0)
            {
                ++a[i - 1];
            }
        }
    }

    long long t = 0;

    for(long long i = 1e6; i > 0; --i)
    {
        if(a[i] == 0)
            continue;

        if(t != 0)
        {
            a[i] -= 2;
            ans += i * t;
            t = 0;
        }

        while(a[i] >= 4)
        {
            ans += i * i;
            a[i] -= 4;
        }

        if(a[i] % 4 != 0)
        {
            t = i;
            a[i] -= 2;
        }
    }

    cout << ans << endl;

    return 0;
}