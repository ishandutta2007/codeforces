#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxl = 100007;
static int mod, mprimes[12], mpow[12][maxl], mcnt, phi;
const int maxn = 100007;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int mul(int a, int b, int m = mod) { return (long long) a * b % m; }
int qpow(int a, int p, int m = mod)
{
    int ans = 1;
    while (p) {
		if (p & 1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        p >>= 1;
    }
    return ans;
}

inline int getpow(int i, int p) { return (p < maxl ? mpow[i][p] : qpow(mprimes[i], p)); }

void initMod()
{
	int x = mod; mcnt = 0; phi = mod;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
    	phi = phi - phi / i;
        mprimes[++mcnt] = i;
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 1) {
    	phi = phi - phi / x;
        mprimes[++mcnt] = x;
    }

    for (int i = 1; i <= mcnt; ++i) {
        mpow[i][0] = 1;
        for (int j = 1; j < maxl; ++j) mpow[i][j] = mul(mpow[i][j-1], mprimes[i]);
    }
}

struct Number
{
    int a[12];

    Number() {}

	Number(int x)
	{
        for (int i = 1; i <= mcnt; ++i) {
        	for (a[i] = 0; x % mprimes[i] == 0; x /= mprimes[i], ++a[i]);
        }
        a[0] = x % mod;

        a[11] = a[0]; for (int i = 1; i <= mcnt; ++i) a[11] = mul(a[11], getpow(i, a[i]));
	}

    inline int toInt()
    {
    	return a[11];
    }

    Number operator*(const Number &rhs) const
    {
    	Number ans(1);
    	ans.a[0] = mul(a[0], rhs.a[0]);
        for (int i = 1; i <= mcnt; ++i) ans.a[i] = a[i] + rhs.a[i];

        ans.a[11] = ans.a[0]; for (int i = 1; i <= mcnt; ++i) ans.a[11] = mul(ans.a[11], getpow(i, ans.a[i]));

        return ans;
    }

    Number operator/ (const Number &rhs) const
    {
    	Number ans(1);
    	ans.a[0] = mul(a[0], qpow(rhs.a[0], phi - 1));
        for (int i = 1; i <= mcnt; ++i) ans.a[i] = a[i] - rhs.a[i];

        ans.a[11] = ans.a[0]; for (int i = 1; i <= mcnt; ++i) ans.a[11] = mul(ans.a[11], getpow(i, ans.a[i]));

        return ans;
    }
} base[maxn], a[maxn], it[maxn << 2];
int lazy[maxn << 2];
int n, q;

#define ROOT1 (root << 1)
#define ROOT2 (root << 1 | 1)
#define MID ((lo + hi) >> 1)

void build(int root, int lo, int hi)
{
	it[root] = base[1];
    if (lo < hi) {
        build(ROOT1, lo, MID);
        build(ROOT2, MID+1, hi);
        lazy[root] = add(lazy[ROOT1], lazy[ROOT2]);
    } else {
        lazy[root] = a[lo].toInt();
    }
}

void upd1(int root, int lo, int hi, int l, int r, int x)
{
	if (hi < l || r < lo) return;
    if (l <= lo && hi <= r) { it[root] = it[root] * base[x]; lazy[root] = mul(lazy[root], x); return; }
    upd1(ROOT1, lo, MID, l, r, x);
    upd1(ROOT2, MID+1, hi, l, r, x);
    lazy[root] = mul(it[root].toInt(), add(lazy[ROOT1], lazy[ROOT2]));
}

void upd2(int root, int lo, int hi, int p, int x)
{
    if (lo < hi) {
        it[ROOT1] = it[ROOT1] * it[root]; lazy[ROOT1] = mul(lazy[ROOT1], it[root].toInt());
        it[ROOT2] = it[ROOT2] * it[root]; lazy[ROOT2] = mul(lazy[ROOT2], it[root].toInt());
		it[root] = base[1];

		if (p <= MID) upd2(ROOT1, lo, MID, p, x);
        else upd2(ROOT2, MID+1, hi, p, x);
        lazy[root] = add(lazy[ROOT1], lazy[ROOT2]);
    } else {
        a[p] = (a[p] * it[root]);
//        for (int i = 1; i <= mcnt; ++i) cerr << a[p].a[i] << ' '; cerr << endl;
//        for (int i = 1; i <= mcnt; ++i) cerr << base[x].a[i] << ' '; cerr << endl;
        a[p] = a[p] / base[x];
        it[root] = base[1];
        lazy[root] = a[p].toInt();
    }
}

int get3(int root, int lo, int hi, int l, int r)
{
	if (hi < l || r < lo) return 0;
    if (l <= lo && hi <= r) { return lazy[root]; }
    return mul(it[root].toInt(), add(get3(ROOT1, lo, MID, l, r), get3(ROOT2, MID+1, hi, l, r)));
}

int main()
{
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> mod;
    initMod();

	for (int i = 1; i < maxn; ++i) base[i] = Number(i);

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = base[x];
    }
    build(1, 1, n);

	cin >> q;
	int t, l, r, p, x;
	while (q--) {
        cin >> t;
        if (t == 1) {
        	cin >> l >> r >> x;
        	upd1(1, 1, n, l, r, x);
        } else if (t == 2) {
            cin >> p >> x;
            upd2(1, 1, n, p, x);
        } else {
            cin >> l >> r;
            cout << get3(1, 1, n, l, r) << '\n';
        }
	}

	return 0;
}