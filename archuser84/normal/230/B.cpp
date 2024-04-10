#include <iostream>
#include <math.h>
using namespace std;

bool pTest(int x)
{
	if (x <= 1)
		return 0;
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

bool tTest(long long x)
{
	long long sqt = sqrt(x);
	while (sqt*sqt < x)sqt++;
	if (sqt*sqt > x)
		return 0;
	else
		return pTest(sqt);
}

int main()
{
	int n;
	long long x[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cout << (tTest(x[i]) ? "YES" : "NO") << endl;
}