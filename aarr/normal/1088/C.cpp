#include <iostream>

using namespace std;

long long a[100005];
const int N = 500 * 1000 - 5;
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	cout << n + 1 << endl;
	for(int i = n; i > 0; i --)
	{
		cout << 1 << " " << i << " " << N + (i % N) - (a[i] % N) << endl;
		for(int j = 1; j <= i; j ++)
		{
			a[j] += N + (i % N) - (a[i] % N);
		}
	}
	cout << 2 << " " << n << " " << N << endl;
	return 0;
}