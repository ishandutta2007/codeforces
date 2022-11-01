#include <iostream>

using namespace std;

int a[105];
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	int s = 0;
	for(int i = 0; i < n; i ++)
	{
		int a;
		cin >> a;
		s += a;
	}
	cout << max(2 * n * k - 2 * s - n, 0);
	return 0;
}