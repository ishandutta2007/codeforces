#include <cstdio>
#include <vector>

using namespace std;

std::vector <long long> numbers;
bool sign[100005];

int main()
{
	int n = 0;
	scanf ("%i", &n);

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf ("%i", &x);
		numbers.push_back (x);
	}

	long long sum = numbers[n - 1];
	sign[n - 1] = true;

	for (int i = n - 2; i >= 0; i--)
	{
		if (sum >= 1)
		{
			sign[i] = false;
			sum -= numbers[i];
		}
		else
		{
			sign[i] = true;
			sum += numbers[i];
		}
	}

	if (sum < 0)
	{
		for (int i = 0; i < n; i++)
			sign[i] = !sign[i];
	}

	for (int i = 0; i < n; i++)
		printf ("%c", sign[i] ? '+' : '-');
	printf ("\n");
	return 0;
}