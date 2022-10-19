#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct ban
{
	int x, y;
};
bool operator<(const ban c, const ban d)
{
	if (c.y < d.y)
		return true;
	return false;
}
ban a[102];
int main()
{
	int i, j, k, n, m;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i].y;
		a[i].x = i;
	}
	sort(a, a + n);
	for (i = 0, j = n - 1; i < n, j >= 0; i++, j--)
	{
		cout << a[i].x+1<<' ' << a[j].x+1;
		cout << endl;
		if (j - i == 1)
			break;
	}
	return 0;
}