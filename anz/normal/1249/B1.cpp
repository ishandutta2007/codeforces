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
int p[200001];
int ans[200001];
int is[200001];
vector <int> w;

void DFS(int s)
{
	is[s] = 1;
	w.push_back(s);
	if (!is[p[s]]) DFS(p[s]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) is[i] = 0;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i <= n; i++)
		{
			w.clear();
			if (is[i] == 0) DFS(i);
			for (auto it : w)
			{
				ans[it] = w.size();
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << "\n";
	}
}