#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 500000;

int m[N + 1];

class segmentTree
{
private:
	const int nullValue = N;
	struct node
	{
		int v;
		int l, r;
		node(int value, int left, int right)
		{
			v = value;
			l = left;
			r = right;
		}
		node()
		{
			v = -1;
			l = -1;
			r = -1;
		}
	};
	node tree[1048576];

	int parent(int n) { return (n - 1) / 2; }
	int left(int n) { return 2 * n + 1; }
	int right(int n) { return 2 * n + 2; }

	int merge(int a, int b)
	{
		if (m[a] <= m[b])
			return a;
		else
			return b;
	}
	int create(int n, int l, int r)
	{
		if (l == r)
			tree[n] = node(l, l, r);
		else
		{
			tree[n] = node(
				merge(create(left(n), l, (l + r) / 2),
					create(right(n), (l + r) / 2 + 1, r))
				, l, r);
		}
		return tree[n].v;
	}
	int getValue(int n, int l, int r)
	{
		if (tree[n].r < l || tree[n].l > r)
			return nullValue;
		else if (tree[n].l >= l && tree[n].r <= r)
			return tree[n].v;
		else
			return merge(getValue(left(n), l, r),
				getValue(right(n), l, r));
	}
public:
	void Create(int size)
	{
		create(0, 0, size - 1);
	}
	int GetValue(int l, int r)
	{
		return getValue(0, l, r);
	}
}T;

pair<int, ll> Solve(int l, int r)
{
	if (r == l)
		return { l, m[l] };
	if (r < l)
		return { -1, -1000000000 };
	int k = T.GetValue(l, r);
	auto a1 = Solve(k + 1, r); a1.second += (ll)(k + 1 - l) * m[k];
	auto a2 = Solve(l, k - 1); a2.second += (ll)(r - k + 1) * m[k];
	if (a1.second >= a2.second)
		return a1;
	else
		return a2;
}

int main()
{
	m[N] = 2000000000;
	int n;
	cin >> n;
	Loop(i, 0, n)
		cin >> m[i];
	T.Create(n);
	int i = Solve(0, n - 1).first;
	int a[N]; a[i] = m[i];
	int miin = m[i];
	LoopR(j, 0, i)
	{
		int x = min(miin, m[j]);
		a[j] = x;
		miin = x;
	}
	miin = m[i];
	Loop(j, i + 1, n)
	{
		int x = min(miin, m[j]);
		a[j] = x;
		miin = x;
	}

	Loop(x, 0, n)
		cout << a[x] << ' ';
}