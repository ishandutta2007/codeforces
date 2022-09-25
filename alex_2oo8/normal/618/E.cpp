#include<bits/stdc++.h>

using namespace std;

const int MX = 300000;
const double pi = 3.141592653589793;

struct {
	int l, r, lSon, rSon;
	long double d, alpha, beta;
} t[2 * MX];

int build_tree(int l, int r) {
	static int tw = 0;
	
	int v = ++tw;
	t[v].l = l;
	t[v].r = r;
	t[v].d = r - l + 1;
	t[v].alpha = 0.0;
	t[v].beta = 0.0;
	if (l != r) {
		t[v].lSon = build_tree(l, (l + r) / 2);
		t[v].rSon = build_tree((l + r) / 2 + 1, r);
	}
	
	return v;
}

void recalc(int v) {
	long double x = t[t[v].lSon].d * cos(t[t[v].lSon].alpha);
	long double y = t[t[v].lSon].d * sin(t[t[v].lSon].alpha);
	
	x += t[t[v].rSon].d * cos(t[t[v].lSon].beta + t[t[v].rSon].alpha);
	y += t[t[v].rSon].d * sin(t[t[v].lSon].beta + t[t[v].rSon].alpha);
	
	t[v].d = sqrt(x * x + y * y);
	t[v].alpha = atan2(y, x);
	t[v].beta = t[t[v].lSon].beta + t[t[v].rSon].beta;
}

void update_len(int v, int x, int delta) {
	if (t[v].l == t[v].r) {
		t[v].d += delta;
		
		return;
	}
	
	if (x <= t[t[v].lSon].r) update_len(t[v].lSon, x, delta);
	else update_len(t[v].rSon, x, delta);
	
	recalc(v);
}

void update_angle(int v, int x, int delta) {
	if (t[v].l == t[v].r) {
		t[v].alpha -= delta / 180.0 * pi;
		t[v].beta -= delta / 180.0 * pi;
		
		return;
	}
	
	if (x <= t[t[v].lSon].r) update_angle(t[v].lSon, x, delta);
	else update_angle(t[v].rSon, x, delta);
	
	recalc(v);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	build_tree(1, n);
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		if (x == 1) update_len(1, y, z);
		else update_angle(1, y, z);
		
		printf("%.6f %.6f\n", (double)(t[1].d * cos(t[1].alpha)), (double)(t[1].d * sin(t[1].alpha)));
	}
	
	return 0;
}