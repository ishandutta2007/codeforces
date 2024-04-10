#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
mt19937 rng(1145141);
int n, m, ans[N];
struct Node {
	int b, a, tagb, taga;
	int lson, rson, sz;
} tr[N];
inline void pushup(int i) {
	tr[i].sz = 1 + tr[tr[i].lson].sz + tr[tr[i].rson].sz;
}
inline void pushdown(int i) {
	if (tr[i].tagb) {
		if (tr[i].lson) {
			tr[tr[i].lson].b += tr[i].tagb;
			tr[tr[i].lson].tagb += tr[i].tagb;
		}
		if (tr[i].rson) {
			tr[tr[i].rson].b += tr[i].tagb;
			tr[tr[i].rson].tagb += tr[i].tagb;
		}
		tr[i].tagb = 0;
	}
	if (tr[i].taga) {
		if (tr[i].lson) {
			tr[tr[i].lson].a += tr[i].taga;
			tr[tr[i].lson].taga += tr[i].taga;
		}
		if (tr[i].rson) {
			tr[tr[i].rson].a += tr[i].taga;
			tr[tr[i].rson].taga += tr[i].taga;
		}
		tr[i].taga = 0;
	}
}
pair<int, int> Split(int p, int x) {
	if (!p) return make_pair(0, 0);
	pushdown(p);
	pair<int, int> ret;
	if (tr[p].b > x) {
		ret = Split(tr[p].lson, x);
		tr[p].lson = ret.second;
		ret.second = p;
	} else {
		ret = Split(tr[p].rson, x);
		tr[p].rson = ret.first;
		ret.first = p;
	}
	pushup(p);
	return ret;
}
int Merge(int p, int q) {
	if (!p || !q) return p | q;
	if (uniform_int_distribution<int>(1, tr[p].sz + tr[q].sz)(rng) <= tr[p].sz) {
		pushdown(p);
		tr[p].rson = Merge(tr[p].rson, q);
		pushup(p);
		return p;
	} else {
		pushdown(q);
		tr[q].lson = Merge(p, tr[q].lson);
		pushup(q);
		return q;
	}
}
int Insert(int rt, int p) {
	int p1, p2;
	tie(p1, p2) = Split(rt, tr[p].b);
	return Merge(Merge(p1, p), p2);
}
void Gao(int &p1, int p2, int c) {
	if (!p2) return;
	pushdown(p2);
	Gao(p1, tr[p2].lson, c);
	Gao(p1, tr[p2].rson, c);
	tr[p2].a++;
	tr[p2].b -= c;
	tr[p2].lson = tr[p2].rson = 0;
	tr[p2].sz = 1;
	p1 = Insert(p1, p2);
}
void Get_ans(int p) {
	if (!p) return;
	pushdown(p);
	ans[p] = tr[p].a;
	Get_ans(tr[p].lson);
	Get_ans(tr[p].rson);
}
struct Dat {
	int c, q;
} dat[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &dat[i].c, &dat[i].q);
	sort(dat + 1, dat + 1 + n, [](Dat a, Dat b) {
		if (a.q != b.q) return a.q > b.q;
		else return a.c < b.c;
	});
	scanf("%d", &m);
	int root = 0;
	tr[0].lson = tr[0].rson = tr[0].sz = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &tr[i].b);
		tr[i].a = 0;
		tr[i].tagb = 0;
		tr[i].taga = 0;
		tr[i].lson = tr[i].rson = 0;
		tr[i].sz = 1;
		root = Insert(root, i);
	}
	for (int i = 1; i <= n; i++) {
		int c = dat[i].c;
		int p1, p2, p3;
		tie(p1, p2) = Split(root, c - 1);
		tie(p2, p3) = Split(p2, 2 * c - 1);
		tr[p3].b -= c;
		tr[p3].tagb -= c;
		tr[p3].a++;
		tr[p3].taga++;
		Gao(p1, p2, c);
		root = Merge(p1, p3);
	}
	Get_ans(root);
	for (int i = 1; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
	return 0;
}