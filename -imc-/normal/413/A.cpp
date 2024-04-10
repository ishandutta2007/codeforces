#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m, xmin, xmax;
	scanf("%d %d %d %d", &n, &m, &xmin, &xmax);

	bool wasMin = false, wasMax = false;
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		if (x < xmin || x > xmax)
		{
			printf("Incorrect\n");
			return 0;
		}
		if (x == xmin) wasMin = true;
		if (x == xmax) wasMax = true;
	}

	printf("%s\n", n - m - !wasMin - !wasMax >= 0 ? "Correct" : "Incorrect");

	return 0;
}