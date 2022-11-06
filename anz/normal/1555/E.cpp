#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 1000001;

int segTree[N * 4];
int cnt[N * 4];

void update(int ptr, int l, int r, int i, int j, int val)
{
	if (j < l || r < i) return;
	if (i <= l && r <= j)
		cnt[ptr] += val;
	else
	{
		update(ptr * 2, l, (l + r) / 2, i, j, val);
		update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j, val);
	}

	if (cnt[ptr]) segTree[ptr] = r - l + 1;
	else
	{
		if (l == r) segTree[ptr] = 0;
		else segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
	}
}

int n, m;

vector <pair<int, pii> > ln;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int l, r, w; cin >> l >> r >> w; r--;
		ln.push_back({ w, {l,r} });
	}

	sort(ln.begin(), ln.end());
	
	int ans = 1e9;

	int rp = 0;

	for (int i = 0; i < n; i++)
	{
		while (rp < n && segTree[1] < m - 1)
		{
			int l = ln[rp].second.first;
			int r = ln[rp].second.second;

			update(1, 1, m - 1, l, r, 1);

			++rp;
		}

		if (segTree[1] < m - 1) break;

		int res = ln[rp - 1].first - ln[i].first;
		ans = min(ans, res);

		int l = ln[i].second.first;
		int r = ln[i].second.second;

		update(1, 1, m - 1, l, r, -1);
	}

	cout << ans;
}