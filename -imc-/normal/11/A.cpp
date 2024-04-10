#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n, d;
	scanf ("%d %d", &n, &d);

	int current = 0;

	long long answer = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf ("%d", &x);
		if (x <= current)
		{
			long long steps = (current - x) / d;
			x += steps * d;
			while (x <= current)
			{
				x += d;
				steps++;
			}
			answer += steps;
		}
		current = x;
	}

	cout << answer << endl;

	return 0;
}