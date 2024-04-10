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
int n, m;
int a[301], mx[301][301];
pair <int, int> b[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i].fr >> b[i].sc;
		for (int j1 = b[i].fr; j1 <= b[i].sc; j1++)
		{
			for (int j2 = b[i].fr; j2 <= b[i].sc; j2++)
			{
				mx[j1][j2]++;
			}
		}
	}

	int max = 0, min = 1e7, ind = 0, maxx = 0;
	for (int i = 0; i <= n; i++)
	{
		min = 1e7;
		max = -min;
		for (int j = 0; j < n; j++)
		{
			int sm = a[j] - mx[i][j + 1];
			if (sm > max)
				max = sm;
			if (sm < min)
				min = sm;
		}
		if (max - min > maxx)
		{
			maxx = max - min;
			ind = i;
		}
	}
	vector <int> pat;
	cout << maxx << endl;
	if (!ind) {
		cout << 0 << endl; return 0;
	}
	else
		for (int i = 0; i < m; i++)
		{
			if (b[i].fr <= ind && b[i].sc >= ind)
			{
				pat.push_back(i + 1);
			}
		}
	cout << pat.size() << endl;
	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i] << " ";
	}
	return 0;
}