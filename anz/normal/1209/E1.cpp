#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m;
int mat[5][101];

int ans = 0;
vector <int> cols;

void bf(int s)
{
	if (s == cols.size())
	{
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int t = 0;
			for (int j = 0; j < m; j++) t = max(t, mat[i][j]);
			res += t;
		}

		ans = max(ans, res);
		return;
	}

	int cc = cols[s];
	for (int i = 0; i < n; i++)
	{
		int t = mat[0][cc];
		for (int j = 0; j < n-1; j++)
		{
			mat[j][cc] = mat[j + 1][cc];
		}
		mat[n - 1][cc] = t;
		bf(s + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ans = 0;
		priority_queue <pair<int, pii> > pq;
		cols.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			int a; cin >> a;
			mat[i][j] = a;
			pq.push({ a,{i,j} });
		}

		set <int> col;
		for (int k = 0; k < 5 && !pq.empty(); k++)
		{
			auto v = pq.top(); pq.pop();
			col.insert(v.second.second);
		}

		for (auto i : col)
			cols.push_back(i);

		bf(0);
		cout << ans << "\n";
	}
}