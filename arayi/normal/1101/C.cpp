#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
struct el 
{
	int a, b, c;
};
bool operator<(const el &x, const el &y)
{
	return x.a < y.a;
}
int n[50001], t, pat[100001];
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		el a[100001];
		cin >> n[i];
		for (int j = 0; j < n[i]; j++)
		{
			cin >> a[j].a >> a[j].b;
			a[j].c = j;
		}
		sort(a, a + n[i]);
		int b = a[0].b;
		int j = 0;
		bool k = 1;
		while (j < n[i] && b >= a[j].a)
		{
			if (a[j].b > b)
			{
				b = a[j].b;
			}
			if (!i)
				pat[a[j].c] = 1;
			else
				pat[n[i - 1] + a[j].c] = 1;
			j++;
		}
		if (j == n[i] && i)
			pat[n[i - 1]] = 2;
		else if (j == n[i])
			pat[0] = 2;
		if (i)
			n[i] += n[i - 1];
	}
	int j = 0;
	for (int i = 0; i < n[t-1]; i++)
	{
		if (i == n[j])
		{
			cout << endl;
			j++;
		}
		if (pat[i] == 2)
		{
			cout << -1;
			if (j)
				i += n[j] - n[j - 1] - 1;
			else
				i += n[0] - 1;
		}
		else if (pat[i])
			cout << 1 << " ";
		else if (!pat[i])
			cout << 2 << " ";
	}
	return 0;
}