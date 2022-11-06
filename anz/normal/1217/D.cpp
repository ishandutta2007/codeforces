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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m;
pii edges[5001];
int ans[5001];

bool cache[5001];
vector <pii> graph[5001];

int hasSearched[5001];

bool hc = false;
void DFS(int s)
{
	hasSearched[s] = 1;
	for (int i = 0; i < graph[s].size(); i++)
	{
		int c = graph[s][i].first;
		int idx = graph[s][i].second;
		if (hasSearched[c] == 1)
		{
			hc = true;
			ans[idx] = 2;
		}
		else
		{
			ans[idx] = 1;
		}

		if (hasSearched[c] == 0)
		{
			DFS(c);
		}
	}
	hasSearched[s] = 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		edges[i] = { a,b };
		graph[a].push_back({ b,i });
	}

	for (int i = 1; i <= n; i++)
	{
		if (hasSearched[i] == 0) DFS(i);
	}

	if (hc) cout << "2\n";
	else cout << "1\n";

	for (int i = 0; i < m; i++)
		cout << ans[i] << ' ';
}