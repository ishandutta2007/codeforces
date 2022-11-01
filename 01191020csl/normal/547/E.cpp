#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int a[400001], id[400001], len, m;
int st[200001];
string s[200001];
int sa[400001], rk[400001];
int tp[400001], h[400050];
int ht[400001], src[400001];
void qsort() {
	for (int i = 1; i <= m; i++) h[i] = 0;
	for (int i = 1; i <= len; i++) ++h[rk[i]];
	for (int i = 1; i <= m; i++) h[i] += h[i-1];
	for (int i = len; i >= 1; i--) sa[h[rk[tp[i]]]--] = tp[i];
}
void getsa() {
	for (int i = 1; i <= len; i++) rk[i] = a[i], tp[i] = i, m = max(m, rk[i]);
	qsort();
	for (int w = 1, p = 0; p < len; m = p, w <<= 1) {
		p = 0;
		for (int i = 1; i <= w; i++) tp[++p] = len + i - w;
		for (int i = 1; i <= len; i++)
			if (sa[i] > w) tp[++p] = sa[i] - w;
		qsort(), p = 0;
		for (int i = 1; i <= len; i++) tp[i] = rk[i];
		for (int i = 1; i <= len; i++)
			rk[sa[i]] = tp[sa[i]] == tp[sa[i-1]] && tp[sa[i]+w] == tp[sa[i-1]+w] ? p : ++p;
	}
	int p = 0;
	for (int i = 1; i <= len; i++) {
		if (p) --p;
		if (rk[i] == 1) continue;
		int j = sa[rk[i]-1];
		while (i + p <= len && j + p <= len && a[i+p] == a[j+p]) ++p;
		ht[rk[i]] = p;
	}
}
int f[400001][20], lg2[400001];
void init() {
	for (int i = 1; i <= len; i++) f[i][0] = ht[i], src[i] = id[sa[i]];
	for (int j = 1; j < 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= len; i++)
			f[i][j] = min(f[i][j-1], f[i+(1<<j-1)][j-1]);
	for (int j = 0; j < 20; j++)
		for (int i = 1 << j; i < (1 << j+1) && i <= len; i++)
			lg2[i] = j;
}
int query(int l, int r) {
	if (l == r) return 0x3f3f3f3f;
	++l;
	int len = lg2[r-l+1];
	return min(f[l][len], f[r-(1<<len)+1][len]);
}
int lbound(int x, int lcp) {
	int l = 1, r = x;
	while (l < r) {
		int mid = (l + r) / 2;
		if (query(mid, x) >= lcp) r = mid;
		else l = mid + 1;
	}
	return l;
}
int rbound(int x, int lcp) {
	int l = x, r = len;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (query(x, mid) >= lcp) l = mid;
		else r = mid - 1;
	}
	return l;
}
struct node {
	int ls, rs, cnt;
}nd[10000001];
int rt[400001], cnt;
void insert(int &p, int np, int l, int r, int num) {
	p = ++cnt, nd[p] = nd[np], ++nd[p].cnt;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (num <= mid) insert(nd[p].ls, nd[np].ls, l, mid, num);
	else insert(nd[p].rs, nd[np].rs, mid + 1, r, num);
}
int query(int p, int np, int l, int r, int l0, int r0) {
	if (l >= l0 && r <= r0) return nd[p].cnt - nd[np].cnt;
	int mid = (l + r) / 2, ans = 0;
	if (l0 <= mid) ans += query(nd[p].ls, nd[np].ls, l, mid, l0, r0);
	if (r0 > mid) ans += query(nd[p].rs, nd[np].rs, mid + 1, r, l0, r0);
	return ans;
}
int main() {
	int n, q;
	n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		st[i] = len + 1;
		for (int j = 0; j < s[i].size(); j++) a[++len] = s[i][j] - 'a', id[len] = i;
		a[++len] = i + 25;
	}
	getsa(), init();
	for (int i = 1; i <= len; i++)
		if (src[i]) insert(rt[i], rt[i-1], 1, n, src[i]);
		else rt[i] = rt[i-1];
	for (int i = 1; i <= q; i++) {
		int l, r, k;
		l = read(), r = read(), k = read();
		int lb = lbound(rk[st[k]], s[k].size()), rb = rbound(rk[st[k]], s[k].size());
		write(query(rt[rb], rt[lb-1], 1, n, l, r)), putchar('\n');
	}
}