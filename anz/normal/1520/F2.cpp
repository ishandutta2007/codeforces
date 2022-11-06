#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int query(int l, int r)
{
	cout << "? " << l << ' ' << r << endl;
	int res; cin >> res;
	return r - l + 1 - res;
	return res;
}

int n, t, k;

void answer(int x)
{
	cout << "! " << x << endl;
}

int segTree[800001];
bool isCalc[800001];

void update(int ptr, int l, int r, int i)
{
	if (i < l || r < i) return;
	segTree[ptr]--;
	if (l != r)
	{
		update(ptr * 2, l, (l + r) / 2, i);
		update(ptr * 2 + 1, (l + r) / 2 + 1, r, i);
	}
}

int findkth(int ptr, int l, int r, int k)
{
	if (l == r)
	{
		update(1, 1, n, l);
		return l;
	}

	if (!isCalc[ptr * 2])
	{
		int res = query(l, (l + r) / 2);
		segTree[ptr * 2] = res;
		segTree[ptr * 2 + 1] = segTree[ptr] - res;
		isCalc[ptr * 2] = isCalc[ptr * 2 + 1] = 1;
	}

	if (segTree[ptr * 2] >= k) findkth(ptr * 2, l, (l + r) / 2, k);
	else findkth(ptr * 2 + 1, (l + r) / 2 + 1, r, k - segTree[ptr * 2]);
}

int main()
{
	ios::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);

	cin >> n >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> k;
		if (k == -1) return 0;
		if (!isCalc[1])
		{
			int res = query(1, n);
			segTree[1] = res;
			isCalc[1] = 1;
		}
		int res = findkth(1, 1, n, k);
		answer(res);
	}
}