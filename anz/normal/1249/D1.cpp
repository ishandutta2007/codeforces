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

int n, k;
vector <int> ans;
vector <pair<pii, int> > seg;
set <pii> lp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		seg.push_back({ {l,r},i + 1 });
	}

	sort(seg.begin(), seg.end());

	for (auto it : seg)
	{
		int l = it.first.first;
		int r = it.first.second;
		int idx = it.second;

		while (!lp.empty() && lp.begin()->first < l)
		{
			lp.erase(lp.begin());
		}

		lp.insert({ r,idx });
		if (lp.size() > k)
		{
			ans.push_back((--lp.end())->second);
			lp.erase(--lp.end());
		}
	}

	cout << ans.size() << "\n";
	for (auto it : ans) cout << it << ' ';
}