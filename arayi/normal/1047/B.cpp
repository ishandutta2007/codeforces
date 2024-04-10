#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	long long int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if ((a + b) > max)
			max = a + b;
	}
	cout << max;
    return 0;
}