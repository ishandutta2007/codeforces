#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200010;

int n;
int a[N];
int lmax[N];
int rmax[N];
int segTree[N * 4];
void update(int ptr, int l, int r, int i, int val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int getVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return 1e9 + 1;
	if (i <= l && r <= j) return segTree[ptr];

	return min(getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

vector <int> x;
vector <int> idx[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= n + 1; i++)
		{
			lmax[i] = rmax[i] = 0;
			idx[i].clear();
		}

		for (int i = 1; i <= n * 4; i++) segTree[i] = 1e9 + 1;
		x.clear();

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			x.push_back(a[i]);
		}

		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());

		for (int i = 1; i <= n; i++)
		{
			a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin() + 1;
			idx[a[i]].push_back(i);
			update(1, 1, n, i, a[i]);
		}

		for (int i = 1; i <= n; i++)
			lmax[i] = max(lmax[i - 1], a[i]);

		for (int i = n; i >= 1; i--)
			rmax[i] = max(rmax[i + 1], a[i]);

		bool hasAns = false;
		int ans[3];

		for (int i = 1; i <= n; i++)
		{
			if (idx[i].size() < 3) continue;
			for (int j = 1; j + 1 < idx[i].size(); j++)
			{
				int cidx = idx[i][j];

				int cl = 0;
				int cr = n + 1;

				int l, r;
				l = 0, r = cidx;
				while (l + 1 < r)
				{
					int m = (l + r) / 2;
					if (lmax[m] <= i) l = m;
					else r = m;
				}
				cl = l;

				l = cidx, r = n + 1;
				while (l + 1 < r)
				{
					int m = (l + r) / 2;
					if (rmax[m] <= i) r = m;
					else l = m;
				}
				cr = r;

				if (cl == 0 || cr == n + 1) continue;
				if (lmax[cl] != i || rmax[cr] != i) continue;

				int res = getVal(1, 1, n, cl + 1, cr - 1);
				if (res == i)
				{
					hasAns = true;
					ans[0] = cl;
					ans[1] = cr - cl - 1;
					ans[2] = n - cr + 1;
				}
			}
		}

		if (!hasAns)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}
}