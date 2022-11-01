#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(long long num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int tag[4000001];
void pushdown(int p) {
	if (!tag[p]) return;
	tag[p*2] = tag[p*2+1] = tag[p], tag[p] = 0;
}
void modify(int p, int l, int r, int l0, int r0, int x) {
	if (l >= l0 && r <= r0) {
		tag[p] = x;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (l0 <= mid) modify(p * 2, l, mid, l0, r0, x);
	if (r0 > mid) modify(p * 2 + 1, mid + 1, r, l0, r0, x);
}
int query(int p, int l, int r, int x) {
	if (l == r) return tag[p];
	pushdown(p);
	int mid = (l + r) / 2;
	if (x <= mid) return query(p * 2, l, mid, x);
	else return query(p * 2 + 1, mid + 1, r, x);
}
int len;
long long c[1000001];
void add(int x, int op) {
	for (; x <= len; x += x & -x) c[x] += op;
}
long long query(int x) {
	long long ans = 0;
	for (; x; x -= x & -x) ans += c[x];
	return ans;
}
int head[1000001], ver[1000001], nxt[1000001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
}
int l[1000001], r[1000001], now;
void dfs(int x) {
	l[x] = ++now;
	for (int i = head[x]; i; i = nxt[i]) dfs(ver[i]);
	r[x] = now;
}
int op[500001], x[500001], y[500001];
int id[1000001], size[1000001];
struct Query {
	int op, t, id;
}q[1000001];
bool operator<(const Query &a, const Query &b) {
	return a.t < b.t;
}
long long ans[500001];
int main() {
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		op[i] = getchar();
		while (!isalpha(op[i])) op[i] = getchar();
		if (op[i] == 'U') op[i] = 1;
		else if (op[i] == 'M') op[i] = 2;
		else if (op[i] == 'A') op[i] = 3;
		else if (op[i] == 'Z') op[i] = 4;
		else op[i] = 5;
		if (op[i] == 1 || op[i] == 2) x[i] = read(), y[i] = read();
		else x[i] = read();
	}
	int cnt = n;
	for (int i = 1; i <= n; i++) id[i] = i;
	for (int i = 1; i <= m; i++)
		if (op[i] == 2) {
			++cnt;
			addedge(cnt, id[x[i]]), addedge(cnt, id[y[i]]);
			id[x[i]] = cnt;
		}
	for (int i = cnt; i >= 1; i--)
		if (!l[i]) dfs(i);
	len = cnt, cnt = n;
	int num = 0;
	for (int i = 1; i <= n; i++) id[i] = i;
	for (int i = 1; i <= m; i++) {
		if (op[i] == 2) id[x[i]] = ++cnt;
		if (op[i] == 4) modify(1, 1, len, l[id[x[i]]], r[id[x[i]]], i);
		if (op[i] == 5) {
			++num, q[num].op = -1, q[num].t = query(1, 1, len, l[x[i]]), q[num].id = i;
			++num, q[num].op = 1, q[num].t = i, q[num].id = i;
		}
	}
	sort(q + 1, q + num + 1);
	cnt = n, sz = 0;
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= n; i++) id[i] = i, size[i] = 1;
	for (int i = 1; i <= m; i++)
		if (op[i] == 1) {
			++cnt;
			addedge(cnt, id[x[i]]), addedge(cnt, id[y[i]]);
			size[cnt] = size[id[x[i]]] = size[id[y[i]]];
			id[x[i]] = cnt;
		}
	now = 0;
	for (int i = 1; i <= cnt; i++) l[i] = 0;
	for (int i = cnt; i >= 1; i--)
		if (!l[i]) dfs(i);
	len = cnt, cnt = n;
	for (int i = 1; i <= n; i++) id[i] = i, size[i] = 1;
	int p = 0;
	while (p < num && !q[p+1].t) ++p;
	for (int i = 1; i <= m; i++) {
		if (op[i] == 1) size[++cnt] = size[id[x[i]]] + size[id[y[i]]], id[x[i]] = cnt;
		if (op[i] == 3) add(l[id[x[i]]], size[id[x[i]]]), add(r[id[x[i]]] + 1, -size[id[x[i]]]);
		while (p < num && q[p+1].t == i) ++p, ans[q[p].id] += q[p].op * query(l[x[q[p].id]]);
	}
	for (int i = 1; i <= m; i++)
		if (op[i] == 5) write(ans[i]), putchar('\n');
}