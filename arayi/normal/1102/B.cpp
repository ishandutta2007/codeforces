#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n, k, a[5001], b[5001], c[5001];
vector <int> nerkv[5001];
bool stugnerk(int guyn, int an)
{
	for (int i = 0; i < nerkv[guyn].size(); i++)
	{
		if (nerkv[guyn][i] == an)
			return 0;
	}
	return 1;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	int max = 0;
	for (int i = 0; i < 5001; i++)
	{
		if (b[i] > max)
			max = b[i];
	}
	if (max > k)
	{
		cout << "NO";
		return 0;
	}
	int n1 = n, mx = n - k + 1, sm = 0;
	for (int i = 1; i <= k; i++)
	{
		sm = 0;
		for (int j = 0; j < n; j++)
		{
			if (sm >= mx)
				break;
			if (!c[j] && stugnerk(i, a[j]))
			{
				c[j] = i;
				sm++;
				n1--;
				nerkv[i].push_back(a[j]);
			}
		}
		if (k == i)
			continue;
		mx = n1 - k + i + 1;
	}
	if (n1 < 0 && n1 > 0)
	{
		while (true)
		{
			int aq = 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}