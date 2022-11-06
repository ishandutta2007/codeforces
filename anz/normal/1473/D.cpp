#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200010;
const int INF = 987654321;

int n, m;
string s;

int val[N];
pii segTree[N * 4];

void update(int ptr, int l, int r, int i, int val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = { val, val };
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr].first = min(segTree[ptr * 2].first, segTree[ptr * 2 + 1].first);
	segTree[ptr].second = max(segTree[ptr * 2].second, segTree[ptr * 2 + 1].second);
}

pii getVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return { INF, -INF };
	if (i <= l && r <= j) return segTree[ptr];

	pii lval = getVal(ptr * 2, l, (l + r) / 2, i, j);
	pii rval = getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);

	return { min(lval.first, rval.first), max(lval.second, rval.second) };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		string s;

		fill(segTree, segTree + (n + 1) * 4, pii(INF, -INF));
		
		cin >> s;
		int cur = 0;
		update(1, 0, n, 0, 0);
		val[0] = 0;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '+') cur++;
			else cur--;

			update(1, 0, n, i + 1, cur);
			val[i + 1] = cur;
		}

		while (m--)
		{
			int l, r; cin >> l >> r;
			pii lval = getVal(1, 0, n, 0, l - 1);
			pii rval = getVal(1, 0, n, r, n);

			int last_l = val[l - 1];
			int last_r = val[r];

			rval.first -= last_r - last_l;
			rval.second -= last_r - last_l;

			int res_min = min(lval.first, rval.first);
			int res_max = max(lval.second, rval.second);

			//cout << "ANS:";
			cout << res_max - res_min + 1 << '\n';
		}
	}
}