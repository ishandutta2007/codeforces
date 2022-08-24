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
	int cnt_0 = 0, cnt_1 = 0;
	int sum = 0;
	double rsum = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		string s;
		cin >> s;
		bool good = false;
		bool can = false;
		double cur = 0;
		for (int i = 0; i < (int) s.size(); i++)
		{
			if (s[i] == '.')
			{
				good = true;
			}
			else
			{
				if (good)
				{
					cur = cur * 10 + s[i] - '0';
					if (s[i] != '0')
					{
						can = true;
					}
				}
				else
				{
					cur = cur * 10 + s[i] - '0';
				}
			}
		}
		cur /= 1000;
		cnt_1 += can;
		cnt_0 += !can;
		sum += int(cur);
		rsum += cur;
	}
	double ans = 1e18;
	for (int i = 0; i <= cnt_0; i++)
	{
		if (n - i <= cnt_1)
		{
			ans = min(ans, abs((sum + 0 * i + 1 * (n - i)) - rsum));
		}
	}
	cout << fixed << setprecision(3) << ans << '\n';
}