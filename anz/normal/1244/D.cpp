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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[100001];
ll cl[100001][4];
int res[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++)
		cin >> cl[j][i];
	
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b), graph[b].push_back(a);
	}

	int s = -1;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() > 2)
		{
			cout << -1;
			return 0;
		}

		if (graph[i].size() == 1) s = i;
	}

	ll ans = numeric_limits<ll>::max();
	int fc = -1, r = -1;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			int cv = s;
			int par = -1;
			ll tmp = 0;
			int cc = i;
			tmp += cl[s][cc];

			for (int k = 0; k < n - 1; k++)
			{
				for (int l = 0; l < graph[cv].size(); l++)
				{
					if (graph[cv][l] == par) continue;
					par = cv;
					cv = graph[cv][l];
					break;
				}

				cc = ((cc - 1) + j) % 3 + 1;
				tmp += cl[cv][cc];
			}

			if (ans > tmp)
			{
				ans = tmp;
				fc = i, r = j;
			}
		}
	}

	cout << ans << "\n";

	int cv = s;
	int par = -1;
	int cc = fc;
	res[cv] = cc;

	for (int i = 0; i < n - 1; i++)
	{
		for (int l = 0; l < graph[cv].size(); l++)
		{
			if (graph[cv][l] == par) continue;
			par = cv;
			cv = graph[cv][l];
			break;
		}

		cc = ((cc - 1) + r) % 3 + 1;
		res[cv] = cc;
	}

	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}