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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n, m;
int mat[51][51];

int B[51][51];

bool flag = true;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> mat[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (mat[i][j] == 0 || B[i][j] == 1) continue;
		if (i != n-1 && j != m-1)
		{
			if (mat[i][j] && mat[i + 1][j] && mat[i][j + 1] && mat[i + 1][j + 1])
			{
				ans.push_back({ i + 1,j + 1 });
				B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
				continue;
			}
		}
		if (i != n - 1 && j != 0)
		{
			if (mat[i][j] && mat[i + 1][j] && mat[i][j - 1] && mat[i + 1][j - 1])
			{
				ans.push_back({ i + 1,j });
				B[i][j] = B[i + 1][j] = B[i][j - 1] = B[i + 1][j - 1] = 1;
				continue;
			}
		}
		if (i != 0 && j != m - 1)
		{
			if (mat[i][j] && mat[i - 1][j] && mat[i][j + 1] && mat[i - 1][j + 1])
			{
				ans.push_back({ i,j + 1 });
				B[i][j] = B[i - 1][j] = B[i][j + 1] = B[i - 1][j + 1] = 1;
				continue;
			}
		}
		if (i != 0 && j != 0)
		{
			if (mat[i][j] && mat[i - 1][j] && mat[i][j - 1] && mat[i - 1][j - 1])
			{
				ans.push_back({ i,j });
				B[i][j] = B[i - 1][j] = B[i][j - 1] = B[i - 1][j - 1] = 1;
				continue;
			}
		}
		flag = false;
	}

	if (!flag)
	{
		cout << "-1";
		return 0;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << "\n";
}