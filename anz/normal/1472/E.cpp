#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
const ll INF = 1e12;

int n;
vector <pair<pll, int> > x;
ll ans[N];

pll segTree[N * 4];

void update(int ptr, int l, int r, int i, pll val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = min(segTree[ptr], val);
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

pll getVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return { INF, -1 };
	if (i <= l && r <= j) return segTree[ptr];

	return min(getVal(ptr * 2, l, (l + r) / 2, i, j), getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

vector <ll> vh, vw;
int getIdx(vector <ll>& vec, ll val)
{
	return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		x.clear();
		vh.clear(), vw.clear();

		fill(segTree, segTree + n * 4, pll(INF, -1));

		for (int i = 1; i <= n; i++)
		{
			ll h, w; cin >> h >> w;
			if (h > w) swap(h, w);

			x.push_back({ {h,w}, i });
			vh.push_back(h);
			vw.push_back(w);

			ans[i] = -1;
		}

		sort(vh.begin(), vh.end());
		vh.erase(unique(vh.begin(), vh.end()), vh.end());
		sort(vw.begin(), vw.end());
		vw.erase(unique(vw.begin(), vw.end()), vw.end());

		for (int i = 0; i < n; i++)
		{
			x[i].first.first = getIdx(vh, x[i].first.first);
			x[i].first.second = getIdx(vw, x[i].first.second);
		}

		sort(x.begin(), x.end());

		for (int i = 0; i < x.size();)
		{
			ll ch = x[i].first.first;

			int j = i;
			while (j + 1 < x.size() && x[j + 1].first.first == ch) j++;

			vector <pair<pll, int> > v;
			for (; i <= j; i++)
			{
				v.push_back(x[i]);

				pll res = getVal(1, 0, n - 1, 0, ch - 1);
				if (res.first < x[i].first.second)
				{
					ans[x[i].second] = res.second;
				}
			}

			for (auto it : v)
			{
				update(1, 0, n - 1, it.first.first, pll(it.first.second, it.second));
			}
		}

		for (int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}