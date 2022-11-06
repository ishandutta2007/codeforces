#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll N = 200001;

vector <ll> x;
int getIdx(ll v) { return lower_bound(x.begin(), x.end(), v) - x.begin(); }

int n;
int cntTree[N * 4];
ll sumTree[N * 4];
int lTree[N * 4];

void lupdate(int ptr, int l, int r, int i, int val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		lTree[ptr] += val;
		return;
	}

	lupdate(ptr * 2, l, (l + r) / 2, i, val);
	lupdate(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	lTree[ptr] = lTree[ptr * 2] + lTree[ptr * 2 + 1];
}

int lgetVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return lTree[ptr];

	return lgetVal(ptr * 2, l, (l + r) / 2, i, j)
		+ lgetVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}

void update(int ptr, int l, int r, int i, ll val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		sumTree[ptr] += val;
		if (val > 0) cntTree[ptr]++;
		else cntTree[ptr]--;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	sumTree[ptr] = sumTree[ptr * 2] + sumTree[ptr * 2 + 1];
	cntTree[ptr] = cntTree[ptr * 2] + cntTree[ptr * 2 + 1];
}

int getSegIdx(int ptr, int l, int r, int val)
{
	if (val == 0) return r + 1;
	if (l == r) return l;

	if (cntTree[ptr * 2 + 1] >= val)
	{
		return getSegIdx(ptr * 2 + 1, (l + r) / 2 + 1, r, val);
	}
	else
	{
		return getSegIdx(ptr * 2, l, (l + r) / 2, val - cntTree[ptr * 2 + 1]);
	}
}

ll getVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return sumTree[ptr];

	return getVal(ptr * 2, l, (l + r) / 2, i, j)
		+ getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}

multiset <ll> st;
vector <pll> query;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll tp, d; cin >> tp >> d;
		query.push_back({ tp,d });
		x.push_back(llabs(d));
	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	ll sum = 0;
	int cl = 0;
	for (auto pll : query)
	{
		ll tp = pll.first;
		ll d = pll.second;

		int idx = getIdx(llabs(d));

		sum += d;

		if (tp == 1)
		{
			if (d > 0)
			{
				lupdate(1, 0, x.size() - 1, idx, 1);
				cl++;
			}
			else
			{
				lupdate(1, 0, x.size() - 1, idx, -1);
				cl--;
			}
		}
		else
		{
			if (d > 0) st.insert(d);
			else st.erase(st.find(-d));
		}

		update(1, 0, x.size() - 1, idx, d);

		int ti = getSegIdx(1, 0, x.size() - 1, cl);

		int lcnt = lgetVal(1, 0, x.size() - 1, ti, x.size() - 1);
		ll res = 0;

		if (lcnt == cl)
		{
			res = getVal(1, 0, x.size() - 1, ti + 1, x.size() - 1);
			if (!st.empty() && cl) res += *prev(st.end());
		}
		else
		{
			res = getVal(1, 0, x.size() - 1, ti, x.size() - 1);
		}

		cout << sum + res << '\n';
	}
}