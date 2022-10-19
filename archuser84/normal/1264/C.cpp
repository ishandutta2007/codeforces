#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 400010;
bool check[N] = { 1 };
int p[N];
int n;

int prediv[101];
ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll mergesucc(pair<ll, ll> a, pair<ll, ll> b)
{
	return (a.first * (b.second + 1) + b.first) % Mod2;
}
ll mergefail(pair<ll, ll> a, pair<ll, ll> b)
{
	return (a.second * (b.second + 1) + b.second) % Mod2;
}

class SegTree
{
private:

	int n;

	int lef(int x) { return 2 * x + 1; }
	int rig(int x) { return 2 * x + 2; }
	int par(int x) { return (x - 1) / 2; }

	struct node
	{
		int l, r;
		ll succ, fail;
		int size() { return r - l + 1; }
	};
	node t[2 * N];
	int arr[N];

	ll smergesucc(int a, int b)
	{
		return (t[a].succ * (t[b].fail + 1) + t[b].succ) % Mod2;
	}
	ll smergefail(int a, int b)
	{
		return (t[a].fail * (t[b].fail + 1) + t[b].fail) % Mod2;
	}

	void create(int s, int l, int r)
	{
		if (l == r)
		{
			t[s].l = t[s].r = l;
			t[s].succ = arr[l];
			t[s].fail = arr[l] - 1;
			return;
		}
		t[s].l = l;
		t[s].r = r;
		int m = (l + r) / 2;
		create(lef(s), l, m);
		create(rig(s), m + 1, r);
		t[s].succ = smergesucc(lef(s), rig(s));
		t[s].fail = smergefail(lef(s), rig(s));
	}

	pair<ll, ll> get(int s, int l, int r)
	{
		if (l <= t[s].l && t[s].r <= r)
			return { t[s].succ, t[s].fail };
		else if (t[s].r < l || t[s].l > r)
			return { 0, 0 };
		else
		{
			auto ans1 = get(lef(s), l, r);
			auto ans2 = get(rig(s), l, r);
			return { mergesucc(ans1,ans2), mergefail(ans1,ans2) };
		}
		return { 0, 0 };
	}

public:

	void Create(int* p, int size)
	{
		n = size;
		Loop(i, 0, n)
			arr[i] = prediv[p[i]];
		create(0, 0, n - 1);
	}

	auto Get(int l, int r)
	{
		return get(0, l, r).first;
	}
}T;

int fen[N] = {};
void fenadd(int a)
{
	int i = a + 1;
	while (i <= n)
	{
		fen[i]++;
		i += i & (-i);
	}
}
void fensub(int a)
{
	int i = a + 1;
	while (i <= n)
	{
		fen[i]--;
		i += i & (-i);
	}
}
int fenget(int a)
{
	int i = a + 1;
	int ans = 0;
	while (i)
	{
		ans += fen[i];
		i -= i & (-i);
	}
	return ans;
}

int binlef(int x)
{
	int k = fenget(x - 1);
	int l = 0, r = x - 1;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (fenget(m) == k)
			r = m;
		else
			l = m + 1;
	}
	return l;
}
int binrig(int x)
{
	int k = fenget(x);
	int l = x, r = n - 1;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		if (fenget(m) == k)
			l = m;
		else
			r = m - 1;
	}
	return l;
}

int main()
{
	FAST;
	fenadd(0);
	Loop(i, 1, 101)
		prediv[i] = modDivide(100, i, Mod2);
	int q;
	cin >> n >> q;
	Loop(i, 0, n)
		cin >> p[i];
	T.Create(p, n);
	ll ans = T.Get(0, n - 1);
	while (q--)
	{
		int x;
		cin >> x; x--;
		if (check[x])
		{
			int l = binlef(x);
			int r = binrig(x);
			ans -= T.Get(l, x - 1);
			ans -= T.Get(x, r);
			ans += T.Get(l, r);
			fensub(x);
		}
		else
		{
			int l = binlef(x);
			int r = binrig(x);
			ans -= T.Get(l, r);
			ans += T.Get(l, x - 1);
			ans += T.Get(x, r);
			fenadd(x);
		}
		check[x] = !check[x];
		cout << ans % Mod2 << '\n';
	}
}