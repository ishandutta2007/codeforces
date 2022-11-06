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
int graph[8][8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	if (n <= 6)
	{
		cout << m;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= 7; i++)
	{
		for (int j = i + 1; j <= 7; j++)
		{
			// i,j are same number
			int res = m;
			for (int k = 1; k <= 7; k++)
			{
				if (k == i || k == j) continue;
				if (graph[k][i] && graph[k][j]) res--;
			}
			ans = max(ans, res);
		}
	}
	cout << ans;
}