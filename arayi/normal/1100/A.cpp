#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int n, k, mx, c, b, a[101], mk, mk1, m, m1;


int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
			mk++;
		else
			mk1++;
	}
	for (int i = 1; i <= n; i++)
	{
		m = mk;
		m1 = mk1;
		b = i;
		int j = -100;
		for (; b + j * k <= 0; j++)
			j = j;
		for (; (b + j*k) <= n; j++)
		{
			if (a[b + j*k] == 1)
				m--;
			else
				m1--;
		}
		if (abs(m - m1) > mx)
			mx = abs(m - m1);
	}
	cout << mx;
	return 0;
}