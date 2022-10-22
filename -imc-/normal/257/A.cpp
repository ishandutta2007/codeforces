#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k;
	scanf ("%i %i %i", &n, &m, &k);

	std::vector <int> devices;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf ("%i", &x);
		devices.push_back (x - 1);
	}

	std::sort (devices.begin(), devices.end());

	int numSlots = k;
	int next = devices.size() - 1;

	while (true)
	{
		if (numSlots >= m)
		{
			printf ("%i\n", devices.size() - 1 - next);
			return 0;
		}

		if (next < 0) break;
		numSlots += devices[next];
		next--;
	}

	printf ("-1\n");
	return 0;
}