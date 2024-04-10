#include <stdio.h>

#define N 500007
int max(int x, int y) { return (x > y ? x : y); }

struct node
{
	bool endp[2], whole;
	int len[2], maxlen;

	node() 
	{
		endp[0] = endp[1] = 0, whole = 1;
		len[0] = len[1] = maxlen = 0;
	}

	void init(bool x) 
	{
		endp[0] = endp[1] = x, whole = true;
		len[0] = len[1] = 1, maxlen = 1;
	}

	void merge(node lc, node rc)
	{
		// printf("%d %d\n", lc.len[0], rc.len[0]); fflush(stdout);
		if (lc.len[0] == 0) { (*this) = rc; return; }
		if (rc.len[0] == 0) { (*this) = lc; return; }
		endp[0] = lc.endp[0], endp[1] = rc.endp[1]; 
		whole = lc.whole && rc.whole;
		maxlen = max(lc.maxlen, rc.maxlen);
		if (lc.endp[1] == 0 && rc.endp[0] == 1) {
			whole = false;
			len[0] = lc.len[0], len[1] = rc.len[1];
			maxlen = max(maxlen, max(lc.len[1], rc.len[0]));
		} else {
			len[0] = lc.len[0] + lc.whole * rc.len[0];
			len[1] = rc.len[1] + rc.whole * lc.len[1];
			maxlen = max(maxlen, lc.len[1] + rc.len[0]);
		}
		maxlen = max(maxlen, max(len[0], len[1]));
	}
} it[N * 4][2];

bool lazy[N * 4], doswap[N * 4];

int n, q;
char s[N];

void build(int rt = 1, int lo = 1, int hi = n)
{
	if (lo == hi) {
		it[rt][0].init(s[lo] == '>');
		it[rt][1].init(s[lo] == '<');
		return;
	}

	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;
	build(lc, lo, md);
	build(rc, md + 1, hi);
	it[rt][0].merge(it[lc][0], it[rc][0]);
	it[rt][1].merge(it[lc][1], it[rc][1]);
	// printf("lo = %d, hi = %d, len[0] = %d, len[1] = %d, maxlen = %d, whole = %d\n", lo, hi, it[rt][0].len[0], it[rt][0].len[1], it[rt][0].maxlen, (int) it[rt][0].whole); fflush(stdout);
}

node query(int l, int r, int rt = 1, int lo = 1, int hi = n)
{
	// printf("%d %d\n", lo, hi); fflush(stdout);
	if (r < lo || hi < l) return node();
	if (l <= lo && hi <= r) {
		lazy[rt] ^= 1; doswap[rt] ^= 1;
		return it[rt][doswap[rt]];
	}

	int md = (lo + hi) >> 1, lc = rt << 1, rc = lc | 1;
	if (lazy[rt]) lazy[rt] = 0, lazy[lc] ^= 1, lazy[rc] ^= 1, doswap[lc] ^= 1, doswap[rc] ^= 1;
	doswap[rt] = 0;
	node x;
	x.merge(query(l, r, lc, lo, md), query(l, r, rc, md + 1, hi));
	it[rt][0].merge(it[lc][doswap[lc]], it[rc][doswap[rc]]);
	it[rt][1].merge(it[lc][doswap[lc] ^ 1], it[rc][doswap[rc] ^ 1]);
	return x;
}

int main()
{
	// freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &q);
	scanf("%s", s + 1);
	build();
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", query(l, r).maxlen);
	}
}