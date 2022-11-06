#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
struct pos
{
	int l;
	int r;
	int idx;

	bool operator<(const pos p) const
	{
		if (r != p.r) return r < p.r;
		else if (l != p.l) return l < p.l;
		return idx < p.idx;
	}
};

bool comp(pos p1, pos p2)
{
	return p1.l < p2.l;
}

const int N = 200001;
pos p[N], tmp[N];
set <pos> st;

int ans1[N], ans2[N];
int ans_idx[N];

pii segTree[N * 4]; // max, idx
void update(int ptr, int l, int r, int i, pii val)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = max(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

pii getVal(int ptr, int l, int r, int i, int j)
{
	if (l > j || r < i) return {0,0};
	if (i <= l && r <= j) return segTree[ptr];

	return max(
		getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r,  i, j)
	);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].l >> p[i].r;
		p[i].idx = i;
		tmp[i] = p[i];
	}

	sort(p, p + n, comp);
	int ptr = 0;
	bool isYes = true;

	for (int i = 0; i < n; i++)
	{
		while (ptr < n && p[ptr].l == i + 1) st.insert(p[ptr++]);

		pos cur = *st.begin();
		st.erase(st.begin());

		ans1[cur.idx] = i + 1;
		ans2[cur.idx] = i + 1;

		ans_idx[i + 1] = cur.idx;
	}

	for (int i = 1; i <= n; i++)
	{
		int idx = ans_idx[i];
		pii v = { tmp[idx].r, idx };
		update(1, 1, n, i, v);

		if (i > 1 && isYes)
		{
			pii res = getVal(1, 1, n, tmp[idx].l, i - 1);
			if (res.first >= i)
			{
				isYes = false;
				swap(ans2[res.second], ans2[idx]);
			}
		}
	}

	if (isYes)
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
	}
	else
	{
		cout << "NO\n";
		for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
		cout << "\n";
		for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
	}
}