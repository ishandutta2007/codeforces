#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct node {
	int tag, maxn, cnt = 0;
}nd[1600001];
void pushdown(int p) {
	nd[p*2].tag += nd[p].tag, nd[p*2+1].tag += nd[p].tag;
	nd[p*2].maxn += nd[p].tag, nd[p*2+1].maxn += nd[p].tag;
	nd[p].tag = 0;
}
void add(int p, int l, int r, int l0, int r0, int x) {
	if (l >= l0 && r <= r0) {
		nd[p].tag += x, nd[p].maxn += x;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (l0 <= mid) add(p * 2, l, mid, l0, r0, x);
	if (r0 > mid) add(p * 2 + 1, mid + 1, r, l0, r0, x);
	nd[p].maxn = max(nd[p*2].maxn, nd[p*2+1].maxn);
}
void modify(int p, int l, int r, int x, int num) {
	if (l == r) {
		nd[p].maxn = num + l;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (x <= mid) modify(p * 2, l, mid, x, num);
	else modify(p * 2 + 1, mid + 1, r, x, num);
	nd[p].maxn = max(nd[p*2].maxn, nd[p*2+1].maxn);
	nd[p].cnt = nd[p*2].cnt + nd[p*2+1].cnt;
}
void addcnt(int p, int l, int r, int x, int num) {
	if (l == r) {
		nd[p].cnt += num;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (x <= mid) addcnt(p * 2, l, mid, x, num);
	else addcnt(p * 2 + 1, mid + 1, r, x, num);
	nd[p].cnt = nd[p*2].cnt + nd[p*2+1].cnt;
}
int query(int p, int l, int r, int l0, int r0) {
	if (l >= l0 && r <= r0) return nd[p].cnt;
	int mid = (l + r) / 2, ans = 0;
	if (l0 <= mid) ans += query(p * 2, l, mid, l0, r0);
	if (r0 > mid) ans += query(p * 2 + 1, mid + 1, r, l0, r0);
	return ans;
}
set<pair<int, int> > vis;
int v[400001];
int main() {
	int n, k, m;
	n = read(), k = read(), m = read();
	add(1, 1, n * 2, 1, n * 2, -0x3f3f3f3f);
	for (int i = 1; i <= m; i++) {
		int x, y;
		x = read(), y = read();
		int p = y + abs(k - x);
		if (vis.find(make_pair(x, y)) != vis.end()) {
			vis.erase(make_pair(x, y));
			add(1, 1, n * 2, 1, p, -1);
			--v[p];
			addcnt(1, 1, n * 2, p, -1);
			if (!v[p]) modify(1, 1, n * 2, p, -0x3f3f3f3f);
		}
		else {
			vis.insert(make_pair(x, y));
			++v[p];
			if (v[p] == 1) modify(1, 1, n * 2, p, query(1, 1, n * 2, p, n * 2) - 1);
			addcnt(1, 1, n * 2, p, 1);
			add(1, 1, n * 2, 1, p, 1);
		}
		cout << max(0, nd[1].maxn - n) << endl;
	}
}