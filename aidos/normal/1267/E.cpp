//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = 105;

using namespace std;

int n, m, a[N][N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	scanf("%d%d", &n, &m);
	forn(j, m)
	{
		forn(i, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0, id = 0;
	for (int i = 1; i < n; i++)
	{
		vector < int > v;
		forn(j, m)
		{
			v.pb(a[i][j] - a[n][j]);
		}
		sort(all(v));
		reverse(all(v));
		int cur = 0;
		for (int j = 0; j < m; j++)
		{
			cur += v[j];
			if (cur >= 0)
			{
				if (j + 1 > ans)
				{
					ans = j + 1;
					id = i;
				}
			}
		}
	}
	cout << m - ans << endl;
	vector < pair < int, int > > v;
	forn(j, m)
		v.pb({a[id][j] - a[n][j], j});
	sort(all(v));
	reverse(all(v));
	vector < int > res;
	for (int i = ans; i < m; i++)
		res.pb(v[i].second);
	sort(all(res));
	for (auto it : res)
		cout << it << ' ';
	cout << endl;

	return 0;
}