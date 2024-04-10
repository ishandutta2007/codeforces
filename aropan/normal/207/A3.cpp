#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector < vector <int> > a; 
int n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	vector < pair < pair < int, int >, int > > v;
	
	cin >> n;
	a.resize(n);
	int ans = 0;
	int K = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		long long l;
		cin >> k >> l;
		long long x, y, m;
		cin >> x >> y >> m;
		a[i].resize(k);
		a[i][0] = l;
		for (int j = 1; j < k; j++)
		{
			l = (l * x + y) % m;
			if (l < 0) l += m;
			a[i][j] = l;
		}
		int res = 0;
		for (int j = 0; j < k; j++)
			if (j && a[i][j - 1] > a[i][j])
				res += 1;
		ans = max(ans, res);
		K += k;
	}
	printf("%d\n", ans);
	
	if (K <= 200000)
	{
		for (int i = 0; i < n; i++)
		{
			int res = 0;
			for (int j = 0; j < (int)a[i].size(); j++)
			{
				if (j && a[i][j - 1] > a[i][j])
					res += 1;
				v.push_back(make_pair(make_pair(res, a[i][j]), i + 1));
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < (int)v.size(); i++)
			printf("%d %d\n", v[i].first.second, v[i].second);
	}
	return 0;
}