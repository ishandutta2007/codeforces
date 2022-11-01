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
struct node {
	int ch[2], fa, tmp, val;
	int size1, size2, maxn, tag;
}nd[400001];
int x[300001], y[300001], w[300001], l[300001], cnt;
struct getmin{
	bool operator()(int x, int y) {
		if (w[x] == w[y]) return x < y;
		return w[x] < w[y];
	}
};
int getmax(int x, int y) {
	if (x >= 0x3f3f3f3f) return y;
	if (y >= 0x3f3f3f3f) return x;
	if (w[x] > w[y]) return x;
	return y;
}
bool isroot(int x) {
	return nd[nd[x].fa].ch[0] != x && nd[nd[x].fa].ch[1] != x;
}
void update(int x) {
	nd[x].size1 = nd[nd[x].ch[0]].size1 + nd[nd[x].ch[1]].size1 + nd[x].size2 + nd[x].tmp;
	nd[x].maxn = getmax(nd[x].val, getmax(nd[nd[x].ch[0]].maxn, nd[nd[x].ch[1]].maxn));
}
void pushdown(int x) {
	if (!nd[x].tag) return;
	swap(nd[nd[x].ch[0]].ch[0], nd[nd[x].ch[0]].ch[1]);
	swap(nd[nd[x].ch[1]].ch[0], nd[nd[x].ch[1]].ch[1]);
	nd[nd[x].ch[0]].tag ^= 1, nd[nd[x].ch[1]].tag ^= 1;
	nd[x].tag = 0;
}
void rotate(int x) {
	int y = nd[x].fa, z = nd[y].fa, k = nd[y].ch[1] == x, w = nd[x].ch[!k];
	if (!isroot(y)) nd[z].ch[nd[z].ch[1]==y]=x; nd[x].fa = z;
	if (w) nd[w].fa = y; nd[y].ch[k] = w;
	nd[x].ch[!k] = y, nd[y].fa = x;
	update(y), update(x);
}
int seq[400001];
void splay(int x) {
	int top = 0;
	for (int u = x; !isroot(u); u = nd[u].fa) seq[++top] = nd[u].fa;
	while (top) pushdown(seq[top--]);
	pushdown(x);
	while (!isroot(x)) {
		int y = nd[x].fa, z = nd[y].fa;
		if (!isroot(y)) {
			if (nd[y].ch[0] == x ^ nd[z].ch[0] == y) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x) {
	for (int u = 0; x; u = x, x = nd[x].fa)
		splay(x), nd[x].size2 += nd[nd[x].ch[1]].size1 - nd[u].size1, nd[x].ch[1] = u, update(x);
}
void makeroot(int x) {
	access(x), splay(x);
	nd[x].tag ^= 1, swap(nd[x].ch[0], nd[x].ch[1]);
}
int findroot(int x) {
	access(x), splay(x);
	while (pushdown(x), nd[x].ch[0]) x = nd[x].ch[0];
	splay(x);
	return x;
}
int odd;
priority_queue<int, vector<int>, getmin> pq1, pq2;
void cut(int x, int y) {
	makeroot(x), access(y), splay(x);
	if (nd[x].size1 & 1) --odd;
	nd[x].ch[1] = nd[y].fa = 0;
	update(x);
	if (nd[x].size1 & 1) ++odd;
	if (nd[y].size1 & 1) ++odd;
}
void link(int x0, int y0, int id) {
	if (!l[id]) {
		l[id] = ++cnt;
		nd[cnt].val = nd[cnt].maxn = id;
	}
	makeroot(x0);
	if (findroot(y0) == x0) {
		int tmp = nd[x0].maxn;
		if (w[tmp] <= w[id]) return;
		cut(l[tmp], x[tmp]), cut(l[tmp], y[tmp]);
		pq2.push(tmp);
		link(x0, y0, id);
		return;
	}
	makeroot(y0);
	if (nd[x0].size1 & 1) --odd;
	if (nd[y0].size1 & 1) --odd;
	nd[x0].fa = nd[y0].fa = l[id], nd[l[id]].size2 = nd[x0].size1 + nd[y0].size1, update(l[id]);
	if (nd[l[id]].size1 & 1) ++odd;
	pq1.push(id);
}
int main() {
	int n, m;
	n = read(), m = read();
	cnt = odd = n;
	for (int i = 1; i <= n; i++) nd[i].size1 = nd[i].tmp = 1, nd[i].val = nd[i].maxn = 0x3f3f3f3f;
	nd[0].val = nd[0].maxn = 0x3f3f3f3f;
	for (int i = 1; i <= m; i++) {
		x[i] = read(), y[i] = read(), w[i] = read();
		link(x[i], y[i], i);
		if (odd) {
			puts("-1");
			continue;
		}
		int tmp = 0;
		while (!odd) {
			while (pq2.size() && pq1.top() == pq2.top()) pq1.pop(), pq2.pop();
			tmp = pq1.top();
			cut(l[tmp], x[tmp]), cut(l[tmp], y[tmp]);
			pq1.pop();
		}
		link(x[tmp], y[tmp], tmp);
		write(w[tmp]), putchar('\n');
	}
}