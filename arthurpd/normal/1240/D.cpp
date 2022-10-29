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

struct node
{
	int val;
	node *left, *right;

	node(int x=0) : val(x), left(NULL), right(NULL) {}
	node(node *l, node *r) : left(l), right(r) { val = (left ? left->val : 0) + (right ? right->val : 0); }

	int get(int l, int r, int a, int b)
	{
		if (l == a && r == b)
			return val;
		int mid = (l + 0ll + r) / 2;
		if (b <= mid)
			return left ? left->get(l, mid, a, b) : 0;
		else if (a > mid)
			return right ? right->get(mid + 1, r, a, b) : 0;
		else
			return (left ? left->get(l, mid, a, mid) : 0) + (right ? right->get(mid + 1, r, mid + 1, b) : 0);		
	}
};

node *p_update(node *prev, int l, int r, int a, int x)
{
	if (l == r)
		return new node(x);

	int mid = (l + 0ll + r) / 2;
	if (a <= mid)
		return new node(p_update(prev ? prev->left : NULL, l, mid, a, x), prev ? prev->right : NULL);
	else
		return new node(prev ? prev->left : NULL, p_update(prev ? prev->right : NULL, mid + 1, r, a, x));
}


#define MAXN 312345

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> q;
	while (q--)
	{
		cin >> n;
		vector<int> a(n + 1, 0);
		vector<int> prox(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<node *> roots(n + 1, NULL);
		roots[n] = new node();

		vector<map<int, int>> rdm(n+1);
		for (int i = n - 1; i >= 0; i--)
		{
			int j = i + 1;
			// while (j < n && prox[j] != -1 && a[j] != a[i])
			// 	j = prox[j];

			// j = roots[j]->get(0, n, a[i], a[i]);
			j = rdm[j][a[i]];

			if (j != 0 && a[i] == a[j])
			{
				prox[i] = j + 1;
				// roots[i] = p_update(roots[prox[i]], 0, n, a[i], i);
				swap(rdm[i], rdm[prox[i]]);
				rdm[i][a[i]] = i;
			}
			else
			{
				prox[i] = -1;
				// roots[i] = p_update(roots[n], 0, n, a[i], i);
				rdm[i][a[i]] = i;
			}
		}

		vector<int> tab(n + 1, 0);
		ll ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (prox[i] == -1)
				tab[i] = 0;
			else
			{
				tab[i] = 1 + tab[prox[i]];
			}
			ans += tab[i];
		}
		// debug(prox);
		// debug(tab);

		cout << ans << endl;
	}
}