#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned int index;

int n;

int main()
{
#ifdef ONPC
	assert(freopen("C:\\Users\\admin\\ClionProjects\\codeforces\\a.in", "r", stdin));
	assert(freopen("C:\\Users\\admin\\ClionProjects\\codeforces\\a.out", "w", stdout));
#else
#endif
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ans += (a[j] > a[i]);
		}
	}
	if (ans % 2 == 0)
	{
		ans *= 2;
	}
	else
	{
		ans = ans * 2 - 1;
	}
	cout << fixed << setprecision(20) << ans << '\n';
}