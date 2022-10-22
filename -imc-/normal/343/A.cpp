#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

long long solve (long long a, long long b)
{
	long long answer = 0;
	while (true)
	{
		//printf ("iteration %lld %lld\n", a, b);
		if (a == b)
		{
			answer += 1;
			break;
		}

		if (a == 0 || b == 0) break;

		if (a > b)
		{
			answer += a / b;
			a = a % b;
		}
		else
		{
			answer += b / a;
			b = b % a;
		}
	}
	return answer;
}

void assertEq (long long a, long long b, long long c)
{
	long long x = solve (a, b);
	//printf ("test %lld %lld: answer %lld, expected %lld\n", a, b, x, c);
	assert (x == c);
}

int main()
{
	long long a, b;
	cin >> a >> b;

	assertEq (1, 1, 1);
	assertEq (3, 2, 3);
	assertEq (199, 200, 200);

	cout << solve (a, b) << endl;

	return 0;
}