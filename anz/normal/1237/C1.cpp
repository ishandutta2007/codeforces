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
ll x[50001], y[50001], z[50001];

ll dist[2001][2001];

bool isDeleted[2001];
vector <pair<ll, pii>> v;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i] >> z[i];

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
	{
		ll dist =
			(x[i] - x[j])*(x[i] - x[j]) +
			(y[i] - y[j])*(y[i] - y[j]) +
			(z[i] - z[j])*(z[i] - z[j]);

		v.push_back({ dist,{i,j} });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		ll dist = v[i].first;
		pii idx = v[i].second;
		if (isDeleted[idx.first] || isDeleted[idx.second]) continue;
		ans.push_back(idx);
		isDeleted[idx.first] = true;
		isDeleted[idx.second] = true;
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << "\n";
}