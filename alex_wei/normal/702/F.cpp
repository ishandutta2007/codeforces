#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, q, ans[N];
struct stuff {
	int q, c;
	bool operator < (const stuff &v) const {
		return q != v.q ? q > v.q : c < v.c;
	}
} c[N];
int R, node, ls[N], rs[N], rd[N];
int val[N], buy[N], dt[N], laz[N];
void down(int x) {
	if(dt[x]) {
		val[ls[x]] += dt[x], val[rs[x]] += dt[x];
		dt[ls[x]] += dt[x], dt[rs[x]] += dt[x], dt[x] = 0;
	}
	if(laz[x]) {
		buy[ls[x]] += laz[x], buy[rs[x]] += laz[x];
		laz[ls[x]] += laz[x], laz[rs[x]] += laz[x], laz[x] = 0;
	}
}
int newnd(int v) {
	int x = ++node;
	val[x] = v, rd[x] = rand();
	return x;
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	down(x), down(y);
	if(rd[x] > rd[y]) return rs[x] = merge(rs[x], y), x;
	return ls[y] = merge(x, ls[y]), y;
}
void split(int p, int &x, int &y, int v) {
	if(!p) return x = y = 0, void();
	down(p);
	if(val[p] > v) split(ls[p], x, ls[y = p], v);
	else split(rs[p], rs[x = p], y, v);
}
vector <int> chk;
void find(int p) {
	if(!p) return;
//	cerr << "find " << p << " " << ls[p] << " " << rs[p] << endl;
	down(p), chk.push_back(p), find(ls[p]), find(rs[p]);
	ls[p] = rs[p] = 0;
}
void insert(int &R, int p) {
//	cerr << "insert " << R << " " << p << endl; 
	int x, y; split(R, x, y, val[p]);
	R = merge(merge(x, p), y);
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i].c >> c[i].q;
	sort(c + 1, c + n + 1), cin >> q;
	for(int i = 1, b; i <= q; i++) cin >> b, insert(R, newnd(b));
	for(int i = 1; i <= n; i++) {
		int x, y, z;
		split(R, x, y, c[i].c - 1);
		split(y, y, z, c[i].c * 2 - 1);
		dt[y] += -c[i].c, val[y] -= c[i].c, laz[y]++, buy[y]++;
		dt[z] += -c[i].c, val[z] -= c[i].c, laz[z]++, buy[z]++;
//		cerr << "split " << x << " " << y << " " << z << " " << c[i].c << endl;
		chk.clear(), find(y);
//		cerr << "chk.size() " << chk.size() << endl; 
		for(int it : chk) insert(x, it);
		R = merge(x, z);
	}
	chk.clear(), find(R); // pushdown
	for(int i = 1; i <= q; i++) printf("%d ", buy[i]);
	return 0;
}

/*
10
12 16
3 16
15 3
11 3
5 3
19 11
10 9
4 11
6 13
17 9
5
69 96 63 98 78

stupid mistakes:
	 split  modify split  
	modify  val  buy  
	 
	 R = merge(R, newnd(b)) b  
notice:
	 id[x] = x
*/