#include <cstdio>
#include <vector>

using namespace std;

int gcd (int a, int b)
{
	while (a && b)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int main()
{
	int n;
	scanf ("%d", &n);

	vector <int> numbers;

	int g = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf ("%d", &x);
		numbers.push_back (x);
		g = gcd (g, x);
	}

	for (int i = 0; i < n; i++)
		numbers[i] /= g;

	int m = 0;
	for (int i = 0; i < n; i++)
		if (numbers[i] > m)
			m = numbers[i];

	printf ("%s\n", (m - n) % 2 == 0 ? "Bob" : "Alice");

	return 0;
}