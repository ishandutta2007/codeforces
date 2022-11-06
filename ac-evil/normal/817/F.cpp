#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>
 
inline ll read() {
    ll w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 100000 + 5;

#define id(v) lower_bound(dsc, dsc+size+1, v) - dsc
ll dsc[maxn << 1];
int size;

namespace SEG {
#define ls (o << 1)
#define rs (o << 1 | 1)
	int tag[maxn<<3];
	ll val[maxn<<3];
	void init() {
		memset(tag, -1, sizeof(tag));
		memset(val, 0, sizeof(val));
	}
	void pushup(int o) {
		val[o] = val[ls] + val[rs];
	}
	void pushdown(int o, int l, int r) {
		if (tag[o] == -1) return;
		int mid = l+r>>1;
		if (tag[o] == 2) {
			val[ls] = dsc[mid+1]-dsc[l]-val[ls], val[rs] = dsc[r+1]-dsc[mid+1]-val[rs];
			if (tag[ls] == 2) tag[ls] = -1; else if (tag[ls] == -1) tag[ls] = 2; else tag[ls] ^= 1;
			if (tag[rs] == 2) tag[rs] = -1; else if (tag[rs] == -1) tag[rs] = 2; else tag[rs] ^= 1;
		} else {
			if (tag[o]) val[ls] = dsc[mid+1]-dsc[l], val[rs] = dsc[r+1]-dsc[mid+1];
			else val[ls] = val[rs] = 0;
			tag[ls] = tag[rs] = tag[o];
		}
		tag[o] = -1;
	}
	void modify(int o, int l, int r, int ql, int qr, int tg) {
		if (ql <= l && r <= qr) {
			if (tg == 2) {
				if (tag[o] == 2) tag[o] = -1;
				else if (tag[o] == -1) tag[o] = 2;
				else tag[o] ^= 1;
			}
			else tag[o] = tg;
			if (tg == 2) val[o] = dsc[r+1]-dsc[l]-val[o];
			else val[o] = tg ? dsc[r+1]-dsc[l] : 0;
			return;
		}
		pushdown(o, l, r);
		int mid = l+r>>1;
		if (ql <= mid) modify(ls, l, mid, ql, qr, tg);
		if (mid < qr) modify(rs, mid+1, r, ql, qr, tg);
		pushup(o);
	}
	ll query(int o, int l, int r) {
		if (l == r) return dsc[l];
		pushdown(o, l, r);
		int mid = l+r>>1;
		if (val[ls] ^ dsc[mid+1]-dsc[l]) return query(ls, l, mid);
		return query(rs, mid+1, r);
	}
};

int N;
int opt[maxn];
ll L[maxn], R[maxn];

int main() {
	SEG::init();
	N = read();
	rep(i, 1, N) opt[i] = read(), L[i] = read(), R[i] = read(), dsc[(i<<1)-1] = L[i], dsc[i<<1] = R[i] + 1;
	sort(dsc+1, dsc+(N<<1)+1);
	dsc[0] = 1;
	size = unique(dsc, dsc+(N<<1)+1) - dsc - 1;
	rep(i, 1, N) {
		SEG::modify(1, 0, size-1, id(L[i]), id(R[i]+1) - 1, opt[i] == 3 ? 2 : 2-opt[i]);
		printf("%lld\n", dsc[size]-dsc[0] == SEG::val[1] ? dsc[size] : SEG::query(1, 0, size-1));
	}
	return 0;
}