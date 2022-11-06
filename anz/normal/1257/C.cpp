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
vector <int> oc[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) oc[i].clear();
		int ans = -1;

		for (int i = 0; i < n; i++)
		{
			int t; cin >> t;
			oc[t].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (oc[i].size() <= 1) continue;
			for (int j = 0; j < oc[i].size() - 1; j++)
			{
				if (ans == -1 || ans > oc[i][j + 1] - oc[i][j] + 1)
					ans = oc[i][j + 1] - oc[i][j] + 1;
			}
		}
		cout << ans << '\n';
	}
}