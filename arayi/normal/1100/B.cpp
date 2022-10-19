#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
int a[100001], m, n, sah, b, j = 1;
string s;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		a[b]++;
		while (a[j] > sah)
		{
			j++;
		}
		if (j > m)
		{
			sah++;
			s += '1';
			j = 1;
		}
		else
			s += '0';
	}
	cout << s;
	return 0;
}