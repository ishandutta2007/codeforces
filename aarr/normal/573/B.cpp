#include <iostream>

using namespace std;

int a[100005];
int dp[100005];
int d[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	dp[0] = 1;
	d[n - 1] = 1;
	for(int i = 1; i < n; i ++)
	{
		dp[i] = min(a[i], dp[i - 1] + 1);
	}
	for(int i = n - 1; i > 0; i --)
	{
		d[i] = min(a[i], d[i + 1] + 1);
	}
	int x = 1;
	for(int i = 0; i < n; i ++)
	{
		int y = min(d[i], dp[i]);
		x = max(x, y);
	}
	cout << endl;
	cout << x;
	return 0;
}