#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

struct segtree
{
	vector<int> val;
	vector<int> delta;

	segtree(int n) : val(4 * (n + 1), 0), delta(4 * (n + 1), 0) {}

	void prop(int id, int l, int r)
	{
		if (l != r)
		{
			// Updates need to be numerically stackable (e.g. not valid to have a list of updates).
			delta[left(id)] += delta[id];
			delta[right(id)] += delta[id];
		}

		val[id] += delta[id]; // Node value needs to be obtainable without propagating all the way to root.
		delta[id] = 0;
	}

	// Sum x in all elements in range [a, b].
	void update(int id, int l, int r, int a, int b, int x)
	{
		if (a == l && b == r)
		{
			delta[id] += x;
			prop(id, l, r);
		}
		else
		{
			prop(id, l, r);
			int mid = (l + r) / 2;
			if (b <= mid)
			{
				update(left(id), l, mid, a, b, x);
				prop(right(id), mid + 1, r);
			}
			else if (a > mid)
			{
				update(right(id), mid + 1, r, a, b, x);
				prop(left(id), l, mid);
			}
			else
			{
				update(left(id), l, mid, a, mid, x);
				update(right(id), mid + 1, r, mid + 1, b, x);
			}

			val[id] = max(val[left(id)], val[right(id)]);
		}
	}

	// Get the minimum value in range [a, b].
	int get(int id, int l, int r, int a, int b)
	{
		prop(id, l, r);
		if (a == l && b == r)
			return val[id];
		else
		{
			int mid = (l + r) / 2;
			if (b <= mid)
				return get(left(id), l, mid, a, b);
			else if (a > mid)
				return get(right(id), mid + 1, r, a, b);
			else
				return max(get(left(id), l, mid, a, mid), get(right(id), mid + 1, r, mid + 1, b));
		}
	}
};

#define MAXN 512345

struct fr
{
	int t, a, b;

	bool operator<(fr rhs) const { return tie(t, a, b) < tie(rhs.t, rhs.a, rhs.b); }
} f[MAXN];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int q, n, m, a, b, t;
	cin >> q;
	while (q--)
	{
		int c0, c;

		cin >> n >> m >> c >> c0;

		for (int i = 1; i <= n; i++)
			cin >> f[i].t >> f[i].a >> f[i].b;

		n++;
		f[n].t = m;
		f[n].a = 0;
		f[n].b = 0;
		sort(f + 1, f + n + 1);

		ll ans = 0;

		segtree seg(n + 1);
		seg.update(1, 0, n, 0, n, c0);
		int prev = 0;

		set<pair<int,int>> friends;
		for (int i = 1; i <= n; i++)
		{
			seg.update(1, 0, n, i, n, -(f[i].t - prev));
			int net = seg.get(1, 0, n, i, i);
			// debug(net);
			while (net < 0)
			{
				if (friends.empty())
				{
					ans = -1;
					goto done;
				}

				int j;
				tie(b, j) = *friends.begin();
				friends.erase(friends.begin());

				int cap = min(-net, min(f[j].a, c - seg.get(1, 0, n, j, i)));

				ans += cap * 1ll * f[j].b;
				net += cap;

				seg.update(1, 0, n, j, n, cap);

				f[j].a -= cap;
				if (f[j].a > 0 && cap > 0)
					friends.insert({f[j].b, j});
			}

			friends.insert({f[i].b, i});
			prev = f[i].t;
		}

		done:
		cout << ans << endl;
	}
}