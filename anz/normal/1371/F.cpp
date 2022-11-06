#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 500001;
struct Node
{
	bool isll;
	int l1, l2;
	bool isrr;
	int r1, r2;

	int mx1, mx2;
	int sz;
	bool notZero;
};

Node Zero;

Node merge(Node n1, Node n2)
{
	if (!n1.notZero) return n2;
	if (!n2.notZero) return n1;

	Node res;
	res.isll = n1.isll;
	if (n1.l1 == n1.sz)
	{
		if (n1.isll == n2.isll)
		{
			res.l1 = n1.l1 + n2.l1;
			res.l2 = n2.l2;
		}
		else
		{
			res.l1 = n1.l1;
			res.l2 = n2.l1;
		}
	}
	else if (n1.l1 + n1.l2 == n1.sz && n1.isll != n2.isll)
	{
		res.l1 = n1.l1;
		res.l2 = n1.l2 + n2.l1;
	}
	else
	{
		res.l1 = n1.l1;
		res.l2 = n1.l2;
	}

	res.isrr = n2.isrr;
	if (n2.r1 == n2.sz)
	{
		if (n2.isrr == n1.isrr)
		{
			res.r1 = n2.r1 + n1.r1;
			res.r2 = n1.r2;
		}
		else
		{
			res.r1 = n2.r1;
			res.r2 = n1.r1;
		}
	}
	else if (n2.r1 + n2.r2 == n2.sz && n2.isrr != n1.isrr)
	{
		res.r1 = n2.r1;
		res.r2 = n2.r2 + n1.r1;
	}
	else
	{
		res.r1 = n2.r1;
		res.r2 = n2.r2;
	}

	res.mx1 = max(n1.mx1, n2.mx1);
//	res.mx1 = max(res.mx1, max(res.l1, res.r1));

	if (n1.isrr)
	{
		int tmp = n1.r1;
		if (n2.isll) tmp += n2.l1;
		else tmp += n2.l1 + n2.l2;

		res.mx1 = max(res.mx1, tmp);
	}
	else
	{
		int tmp = n1.r1 + n1.r2;
		if (n2.isll) tmp += n2.l1;

		res.mx1 = max(res.mx1, tmp);
	}

	res.mx2 = max(n1.mx2, n2.mx2);
//	res.mx2 = max(res.mx2, max(res.l1, res.r1));

	if (!n1.isrr)
	{
		int tmp = n1.r1;
		if (!n2.isll) tmp += n2.l1;
		else tmp += n2.l1 + n2.l2;

		res.mx2 = max(res.mx2, tmp);
	}
	else
	{
		int tmp = n1.r1 + n1.r2;
		if (!n2.isll) tmp += n2.l1;

		res.mx2 = max(res.mx2, tmp);
	}

	res.sz = n1.sz + n2.sz;
	res.notZero = 1;

	return res;
}

Node segTree[N * 4];
// 0 : left, 1 : right
void update(int ptr, int l, int r, int i, int val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		Node cur;
		cur.l1 = 1, cur.l2 = 0;
		cur.r1 = 1, cur.r2 = 0;
		if (val == 0)
			cur.isll = 1, cur.isrr = 0;
		else
			cur.isll = 0, cur.isrr = 1;

		cur.mx1 = 1;
		cur.mx2 = 1;
		cur.sz = 1;
		cur.notZero = 1;

		segTree[ptr] = cur;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = merge(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

bool lazy[N * 4];
void setLazy(int ptr, int l, int r)
{
	lazy[ptr] = 0;
	segTree[ptr].isll = !segTree[ptr].isll;
	segTree[ptr].isrr = !segTree[ptr].isrr;
	swap(segTree[ptr].mx1, segTree[ptr].mx2);

	if (l != r)
	{
		lazy[ptr * 2] = !lazy[ptr * 2];
		lazy[ptr * 2 + 1] = !lazy[ptr * 2 + 1];
	}
}

Node flip(int ptr, int l, int r, int i, int j)
{
	if (lazy[ptr]) setLazy(ptr, l, r);
	if (j < l || r < i) return Zero;
	if (i <= l && r <= j)
	{
		segTree[ptr].isll = !segTree[ptr].isll;
		segTree[ptr].isrr = !segTree[ptr].isrr;
		swap(segTree[ptr].mx1, segTree[ptr].mx2);

		if (l != r)
		{
			lazy[ptr * 2] = !lazy[ptr * 2];
			lazy[ptr * 2 + 1] = !lazy[ptr * 2 + 1];
		}

		return segTree[ptr];
	}

	Node n1 = flip(ptr * 2, l, (l + r) / 2, i, j);
	Node n2 = flip(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);

	segTree[ptr] = merge(segTree[ptr * 2], segTree[ptr * 2 + 1]);

	return merge(n1, n2);
}

int n, q;
string s;

void print()
{
	for (int i = 1; i <= n; i++)
	{
		flip(1, 1, n, i, i);
		Node res = flip(1, 1, n, i, i);
		if (res.isll) cout << "<";
		else cout << ">";
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		update(1, 1, n, i + 1, s[i] == '<' ? 0 : 1);
	}
	while (q--)
	{
		int l, r; cin >> l >> r;
		Node res = flip(1, 1, n, l, r);
		cout << res.mx1 << '\n';

		//print();
	}
}