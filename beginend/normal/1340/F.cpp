#include<bits/stdc++.h>
#define ls d << 1
#define rs d << 1 | 1
using namespace std;

typedef long long LL;

const int N = 100005;
const LL mod1 = 998244353, mod2 = 1000000007;
const LL BAS1 = 131, BAS2 = 233;

int n, k, a[N];
LL mi1[N], mi2[N], inv1[N], inv2[N];

struct str
{
	LL h1, h2;
	int len;
	
	void init(int c = 0)
	{
		if (!c) h1 = h2 = len = 0;
		else h1 = h2 = abs(c), len = 1;
	}
	
	bool operator == (const str& s)
	{
		return len == s.len && h1 == s.h1 && h2 == s.h2;
	}
	
	str operator + (const str& s)
	{
		str res;
		res.h1 = (h1 * mi1[s.len] + s.h1) % mod1;
		res.h2 = (h2 * mi2[s.len] + s.h2) % mod2;
		res.len = len + s.len;
		return res;
	}
	
	str operator - (const str& s)
	{
		str res;
		res.h1 = (h1 - s.h1 + mod1) * inv1[s.len] % mod1;
		res.h2 = (h2 - s.h2 + mod2) * inv2[s.len] % mod2;
		res.len = len - s.len;
		return res;
	}
};

struct seg
{
	bool flag;
	str L, R;
}t[N * 4];

LL pow(LL x, LL y, int mod)
{
	LL ans = 1;
	while (y)
	{
		if (y & 1) ans = ans * x % mod;
		x = x * x % mod; y >>= 1;
	}
	return ans;
}

void init()
{
	mi1[0] = mi2[0] = inv1[0] = inv2[0] = 1;
	for (int  i = 1; i <= n; i++)
	{
		mi1[i] = mi1[i - 1] * BAS1 % mod1;
		mi2[i] = mi2[i - 1] * BAS2 % mod2;
		inv1[i] = pow(mi1[i], mod1 - 2, mod1);
		inv2[i] = pow(mi2[i], mod2 - 2, mod2);
	}
}

pair<str, str> calcL(int d, int l, int r, int len)
{
	if (!len) return make_pair((str){0, 0, 0}, (str){0, 0, 0});
	if (t[d].flag && t[d].L.len == len) return make_pair(t[d].L, t[d].R);
	int mid = (l + r) / 2;
	if (!t[ls].flag) return calcL(ls, l, mid, len);
	else if (t[ls].L.len >= len) return calcL(ls, l, mid, len);
	else
	{
		pair<str, str> tmp = calcL(rs, mid + 1, r, len + t[ls].R.len - t[ls].L.len);
		tmp.first = (tmp.first - t[ls].R) + t[ls].L;
		return tmp;
	}
}

pair<str, str> calcR(int d, int l, int r, int len)
{
	if (!len) return make_pair((str){0, 0, 0}, (str){0, 0, 0});
	if (t[d].R.len == len) return make_pair(t[d].L, t[d].R);
	int mid = (l + r) / 2;
	if (!t[rs].flag) return calcR(rs, mid+1, r, len);
	else if (t[rs].R.len >= len) return calcR(rs, mid + 1, r, len);
	else
	{
		pair<str, str> tmp = calcR(ls, l, mid, len + t[rs].L.len - t[rs].R.len);
		tmp.second = (tmp.second - t[rs].L) + t[rs].R;
		return tmp;
	}
}

seg update(int d, int l, int r, seg t1, seg t2)
{
	seg res;
	res.L.init(); res.R.init();
	if (!t1.flag || !t2.flag)
	{
		res.flag = 0;
		return res;
	}
	int mid = (l + r) / 2;
	if (t1.R.len == t2.L.len)
	{
		res.L = t1.L;
		res.R = t2.R;
		res.flag = t1.R == t2.L;
		return res;
	}
	else if (t1.R.len < t2.L.len)
	{
		pair<str, str> tmp = calcL(rs, mid + 1, r, t1.R.len);
		res.L = (t2.L - tmp.first) + t1.L;
		res.R = t2.R;
		res.flag = t1.R == tmp.first;
		return res;
	}
	else
	{
		pair<str, str> tmp = calcR(ls, l, mid, t2.L.len);
		res.L = t1.L;
		res.R = (t1.R - tmp.second) + t2.R;
		res.flag = tmp.second == t2.L;
		return res;
	}
}

void build(int d, int l, int r)
{
	if (l == r)
	{
		if (a[l] > 0) t[d].L.init(), t[d].R.init(a[l]);
		else t[d].L.init(a[l]), t[d].R.init();
		t[d].flag = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(ls, l, mid);
	build(rs, mid+1, r);
	t[d] = update(d, l, r, t[ls], t[rs]);
}

void modify(int d, int l, int r, int x)
{
	if (l == r)
	{
		if (a[l] > 0) t[d].L.init(), t[d].R.init(a[l]);
		else t[d].L.init(a[l]), t[d].R.init();
		t[d].flag = 1;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) modify(ls, l, mid, x);
	else modify(rs, mid + 1, r, x);
	t[d] = update(d, l, r, t[ls], t[rs]);
}

seg query(int d, int l, int r, int x, int y)
{
	if (x <= l && r <= y) return t[d];
	int mid = (l + r) / 2;
	if (y <= mid) return query(ls, l, mid, x, y);
	else if (x > mid) return query(rs, mid + 1, r, x, y);
	else return update(d, l, r, query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
}

int main()
{
	scanf("%d%d", &n, &k);
	init();
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	int q; scanf("%d", &q);
	while (q--)
	{
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) a[x] = y, modify(1, 1, n, x);
		else
		{
			seg res = query(1, 1, n, x, y);
			puts(res.flag && !res.L.len && !res.R.len ? "Yes" : "No");
		}
	}
	return 0;
}