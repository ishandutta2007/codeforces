#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

char s[MX][42];

namespace seg_tree {
	const int SIZE = 2 * MX;
	
	struct {
		int l, r;
		int lSon, rSon;
		string val[2], here;
		int state;
	} t[SIZE];
	
	int tw = 0;
	
	int newNode(int l, int r) {
		int v = ++tw;
		assert(v < SIZE);
		t[v].l = l;
		t[v].r = r;
		t[v].lSon = t[v].rSon = 0;
		
		return v;
	}
	
	void recalc(int v) {
		int l = t[v].lSon;
		int r = t[v].rSon;
		
		{
			int st = t[l].state;
			if (st == -1) st = 0;
			
			string val = t[r].val[st];
			if (val == "old") val = t[l].val[0];
			
			t[v].val[0] = val;
		}
		
		{
			int st = t[l].state;
			if (st == -1) st = 1;
			
			string val = t[r].val[st];
			if (val == "old") val = t[l].val[1];
			
			t[v].val[1] = val;
		}
		
		t[v].state = t[r].state;
		if (t[v].state == -1) t[v].state = t[l].state;
	}
	
	void calcLeaf(int v) {
		if (t[v].here == "lock") {
			t[v].val[0] = t[v].val[1] = "old";
			t[v].state = 1;
		}
		else if (t[v].here == "unlock") {
			t[v].val[0] = t[v].val[1] = "old";
			t[v].state = 0;
		}
		else {
			t[v].val[0] = t[v].here;
			t[v].val[1] = "old";
			t[v].state = -1;
		}
	}
	
	int build(int l, int r) {
		int v = ++tw;
		assert(v < SIZE);
		t[v].l = l;
		t[v].r = r;
		if (l < r) {
			t[v].lSon = build(l, (l + r) / 2);
			t[v].rSon = build((l + r) / 2 + 1, r);
			
			recalc(v);
		}
		else {
			t[v].here = s[l];
			calcLeaf(v);
		}
		
		return v;
	}
	
	void update(int v, int x, string val) {
		if (t[v].l == t[v].r) {
			t[v].here = val;
			calcLeaf(v);
			
			return;
		}
		
		update(x <= t[t[v].lSon].r ? t[v].lSon : t[v].rSon, x, val);
		
		recalc(v);
	}
	
	string solve() {
		return t[1].val[0] == "old" ? "blue" : t[1].val[0];
	}
}

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%s", s[i]);
	
	seg_tree::build(0, n - 1);

	printf("%s\n", seg_tree::solve().c_str());
	
	int t;
	ignore = scanf("%d", &t);
	for (int i = 0, x; i < t; i++) {
		static char ss[42];
		ignore = scanf("%d %s", &x, ss);
		
		seg_tree::update(1, x - 1, ss);
		
		printf("%s\n", seg_tree::solve().c_str());
	}
	
	return 0;
}