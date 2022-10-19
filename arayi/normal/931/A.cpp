#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, sum = 0, j=1;
	cin >> a;
	cin >> b;
	int c = abs(a - b) / 2;
	for (int i = 1; i <= c; i++)
	{
		sum += i;
		j = i+1;
	}
	sum *= 2;
	if (abs(a - b) % 2 == 1)
		sum += j;
	cout << sum;
}