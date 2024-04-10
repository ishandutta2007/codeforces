#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
long long int a[501];


int main()
{
	long long int q, l, r, d;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> d;
		if (d<l || d>r)
		{
			a[i] = d;
		}
		else
		{
			if (r%d == 0)
			{
				a[i] = r + d;
			}
			else
			{
				a[i] = d * (r / d + 1);
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}