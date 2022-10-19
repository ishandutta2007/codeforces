#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 2e5 + 1;
int n, a[51], pref[51], sm, mx, pat, l, sm1;
int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	for (int i1 = 1; i1 <= n; i1++)
	{
		for (int i2 = 1; i2 <= i1; i2++)
		{
			sm = pref[i1] - pref[i2 - 1];
			mx = 0;
			l = 0;
			for (int i3 = 1; i3 <= n; i3++)
			{
				for (int i4 = l+1; i4 <= i3; i4++)
				{
					if (pref[i3] - pref[i4 - 1] == sm)
					{
						mx++;
						l = i3;
						break;
					}
				}
			}
			if (mx > pat)
			{
				pat = mx;
				sm1 = sm;
			}
		}
	}
	mx = 0;
	l = 0;
	cout << pat << endl;
	for (int i3 = 1; i3 <= n; i3++)
	{
		for (int i4 = l + 1; i4 <= i3; i4++)
		{
			if (pref[i3] - pref[i4 - 1] == sm1)
			{
				cout << i4 << " " << i3 << endl;
				l = i3;
				break;
			}
		}
	}
	return 0;
}