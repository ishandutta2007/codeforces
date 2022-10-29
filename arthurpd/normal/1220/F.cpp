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

#define MAX_RANGE 1123456

int val[4 * MAX_RANGE];
int delta[4 * MAX_RANGE];

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

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


#define MAXN 1123456

int a[MAXN];
int pos[MAXN];
int prox[MAXN];
int ant[MAXN];
int h[MAXN];

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		a[i + n] = a[i];

	for (int i = 1; i <= n; i++)
		pos[a[i]] = i;

	for (int i = 1; i <= 2*n; i++)
	{
		int k = i - 1;
		while (a[k] >= a[i])
			k = ant[k];
		ant[i] = k;
	}

	for (int i = 2*n; i > 0; i--)
	{
		int k = i + 1;
		while (a[k] >= a[i])
			k = prox[k];
		prox[i] = k;
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[ant[pos[i]]] > a[prox[pos[i]]] || prox[pos[i]] > n)
			h[pos[i]] = h[ant[pos[i]]] + 1;
		else
			h[pos[i]] = h[prox[pos[i]]] + 1;
	}

	for (int i = 1; i <= n; i++)
		update(1, 1, 2*n, i, i, h[i]);

	int ans = 0;
	int v = get(1, 1, 2*n, 1, n);

	// debug(v, ans);

	for (int i = 1; i + 1 <= n; i++)
	{

		update(1, 1, 2*n, i, min(i + n, prox[i]) - 1, -1);

		int nh = (ant[i + n] <= i) ? (1) : (get(1, 1, 2*n, ant[i + n], ant[i + n]) + 1);
		update(1, 1, 2*n, i + n, i + n, nh - 1);

		update(1, 1, 2*n, max(ant[i + n], i) + 1, i + n, +1);

		if (get(1, 1, 2*n, i + 1, i + n) < v)
		{
			v = get(1, 1, 2*n, i + 1, i + n);
			ans = i;
		}

		// for (int j = 1; j <= n; j++)
		// 	debug(a[i + j], get(1, 1, 2*n, i + j, i + j));
	}

	cout << v << " " << ans << endl;
}