#include <iostream>

using namespace std;

int a[10];
int main()
{
	int ans = 0;
	for(int i = 1; i <= 5; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= 5; i ++)
	{
		int b;
		cin >> b;
		ans += max(150 * i, i * (500 - a[i] * 2) - 50 * b);
		//cout << i * (500 - a[i] * 2) - 50 * b << endl;
	}
	int x, y;
	cin >> x;
	cin >> y;
	ans += 100 * x - 50 * y;
	cout << ans;
}