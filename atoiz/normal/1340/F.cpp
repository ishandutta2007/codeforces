#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <tuple>

using namespace std;

const int MAXN = (1 << 17);

// hash
const int MOD[2] = {999999001, 999999667};
int add(int x, int y, int m) { return x -= ((x += y) >= m ? m : 0); }
int sub(int x, int y, int m) { return x += ((x -= y) < 0 ? m : 0); }
int mul(int x, int y, int m) { return (int) ((int64_t) x * y % m); }
int inv(int x, int m) { return (x == 1 ? 1 : m - (int) ((int64_t) m * inv(m % x, x) / x)); }
struct Hash
{
	int a[2];
	Hash(int a0 = 0, int a1 = 0) { a[0] = a0, a[1] = a1; };
	friend Hash operator+ (Hash x, Hash y) { return Hash(add(x.a[0], y.a[0], MOD[0]), add(x.a[1], y.a[1], MOD[1])); }
	friend Hash operator- (Hash x, Hash y) { return Hash(sub(x.a[0], y.a[0], MOD[0]), sub(x.a[1], y.a[1], MOD[1])); }
	friend Hash operator* (Hash x, Hash y) { return Hash(mul(x.a[0], y.a[0], MOD[0]), mul(x.a[1], y.a[1], MOD[1])); }
	Hash& operator+= (Hash x) { return (*this) = (*this) + x; }

	friend bool operator== (Hash x, Hash y) { return x.a[0] == y.a[0] && x.a[1] == y.a[1]; }
	friend bool operator!= (Hash x, Hash y) { return x.a[0] != y.a[0] || x.a[1] != y.a[1]; }
};
const Hash BASE = {9123821, 21489122}, INV_BASE = {inv(BASE.a[0], MOD[0]), inv(BASE.a[1], MOD[1])};
Hash powBase[MAXN], powIBase[MAXN];

// segment tree
struct Node
{
	bool fail;
	int len[2];
	Hash hashVal[2], remHash;
	int lc, rc;

	Node()
	{
		fail = false;
		len[0] = len[1];
		hashVal[0] = hashVal[1] = remHash = 0;
		lc = rc = 0;
	}

	Node(int x)
	{
		fail = false;
		len[x > 0] = 1, len[x < 0] = 0;
		hashVal[x > 0] = Hash(abs(x), abs(x)), hashVal[x < 0] = 0, remHash = 0;
		lc = rc = 0;
	}
} it[MAXN * 2 + 1000];

Hash getPowBase(int p) { return (p < 0 ? powIBase[-p] : powBase[p]); }
bool& getFail(int i) { return it[i].fail; }
int& getLen(int i, int k) { return it[i].len[k]; }
Hash& getRemHash(int i) { return it[i].remHash; }
Hash& getHashVal(int i, int k) { return it[i].hashVal[k]; }
Hash getPrefixHash(int c, int k, int rt)
{
	Hash ans = 0;
	while (true) {
		if (c == 0) return ans;
		if (getLen(rt, k) == c) return ans += getHashVal(rt, k);
		assert(getLen(rt, k) > c);

		int lc = it[rt].lc, rc = it[rt].rc;
		if (k == 0) {
			if (getLen(rc, 0) > getLen(lc, 1)) {
				int rLen = getLen(rc, 0) - getLen(lc, 1);
				if (rLen >= c) rt = rc;
				else {
					ans += (getHashVal(rc, 0) - getRemHash(rt)) * getPowBase(c - getLen(rc, 0));
					c -= rLen, rt = lc;
				}
			} else {
				rt = lc;
			}
		} else {
			if (getLen(lc, 1) > getLen(rc, 0)) {
				int lLen = getLen(lc, 1) - getLen(rc, 0);
				if (lLen >= c) rt = lc;
				else {
					ans += (getHashVal(lc, 1) - getRemHash(rt)) * getPowBase(c - getLen(lc, 1));
					c -= lLen, rt = rc;
				}
			} else {
				rt = rc;
			}
		}
	}
}

void merge(int rt, int lc, int rc)
{
	Node &x = it[rt];
	if (getFail(lc) || getFail(rc)) { getFail(rt) = true; return; }
	if (getLen(rc, 0) > getLen(lc, 1)) {
		int rLen = getLen(rc, 0) - getLen(lc, 1);
		Hash pref = getPrefixHash(rLen, 0, rc);
		Hash suff = getHashVal(rc, 0) - pref * powBase[getLen(lc, 1)];
		if (suff != getHashVal(lc, 1)) { getFail(rt) = true; return; }

		x.fail = false;
		x.hashVal[0] = pref * powBase[getLen(lc, 0)] + getHashVal(lc, 0);
		x.hashVal[1] = getHashVal(rc, 1);
		x.len[0] = getLen(lc, 0) + rLen;
		x.len[1] = getLen(rc, 1);
		x.lc = lc, x.rc = rc;
		getRemHash(rt) = suff;
	} else {
		int lLen = getLen(lc, 1) - getLen(rc, 0);
		Hash pref = getPrefixHash(lLen, 1, lc);
		Hash suff = getHashVal(lc, 1) - pref * powBase[getLen(rc, 0)];
		if (suff != getHashVal(rc, 0)) { getFail(rt) = true; return; }

		getFail(rt) = false;
		getHashVal(rt, 0) = getHashVal(lc, 0);
		getHashVal(rt, 1) = pref * powBase[getLen(rc, 1)] + getHashVal(rc, 1);
		getLen(rt, 0) = getLen(lc, 0);
		getLen(rt, 1) = getLen(rc, 1) + lLen;
		getRemHash(rt) = suff;
		x.lc = lc, x.rc = rc;
	}
}

void modify(int i, int x)
{
	it[i += MAXN] = Node(x);
	for (i >>= 1; i > 0; i >>= 1) merge(i, i << 1, i << 1 | 1);
}

bool get(int l, int r)
{
	int counter = MAXN * 2;
	int lx = ++counter, rx = ++counter;
	for (l += MAXN, r += MAXN + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) merge(++counter, lx, l++), lx = counter;
		if (r & 1) merge(++counter, --r, rx), rx = counter;
	}
	int x = ++counter;
	merge(x, lx, rx);
	return !getFail(x) && getHashVal(x, 0) == 0 && getHashVal(x, 1) == 0;
}

int main()
{
	powBase[0] = powIBase[0] = Hash(1, 1);
	for (int i = 1; i < MAXN; ++i) powBase[i] = powBase[i - 1] * BASE, powIBase[i] = powIBase[i - 1] * INV_BASE;

	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		it[MAXN + i] = Node(x);
	}
	for (int i = MAXN - 1; i >= 1; --i) merge(i, i << 1, i << 1 | 1);

	int q;
	scanf("%d", &q);
	while (q--) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 1) modify(x, y);
		else puts(get(x, y) ? "Yes" : "No");	
	}
}