#include <iostream>
#include <string>

using namespace std;

int s(int k)
{
	int j = 0;

	for (int i = 0; i <= 10; i++)
	{
		j += k % 10;
		k /= 10;
	}
	return j;
}

int main()
{
	int n;
	cin >> n;
	int k = n + s(n);
	int ans = 0;
	for (int i = n - 100; i < n; i++)
	{
		if (i + s(i) == n) ans++;
	}
	cout << ans << endl;
	if (ans == 0) return 0;
	for (int i = n - 100; i < n; i++)
	{
		if (i + s(i) == n) cout << i << endl;
	}
	return 0;
}