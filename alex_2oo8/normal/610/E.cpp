#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

struct {
	int l, r, lSon, rSon, first, last, cnt[10][10], debt;
} t[2 * MX];

int k;
char s[MX + 1];

void recalc(int v) {
	t[v].first = t[t[v].lSon].first;
	t[v].last = t[t[v].rSon].last;
	
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			t[v].cnt[i][j] = t[t[v].lSon].cnt[i][j] + t[t[v].rSon].cnt[i][j];
	
	t[v].cnt[t[t[v].lSon].last][t[t[v].rSon].first]++;
}

int build_tree(int l, int r) {
	static int tw = 0;
	int v = ++tw;
	
	t[v].l = l;
	t[v].r = r;
	t[v].debt = -1;
	if (l == r) t[v].first = t[v].last = s[l - 1] - 'a';
	else {
		t[v].lSon = build_tree(l, (l + r) / 2);
		t[v].rSon = build_tree((l + r) / 2 + 1, r);
		
		recalc(v);
	}
	
	return v;
}

void update(int v, int l, int r, int x) {
	if (l <= t[v].l && t[v].r <= r) {
		t[v].first = t[v].last = t[v].debt = x;
		
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				t[v].cnt[i][j] = 0;
		
		t[v].cnt[x][x] = t[v].r - t[v].l;
		
		return;
	}
	
	if (t[v].debt != -1) {
		update(t[v].lSon, t[v].l, t[v].r, t[v].debt);
		update(t[v].rSon, t[v].l, t[v].r, t[v].debt);
		
		t[v].debt = -1;
	}
	
	if (t[t[v].lSon].r >= l) update(t[v].lSon, l, r, x);
	if (t[t[v].rSon].l <= r) update(t[v].rSon, l, r, x);
	
	recalc(v);
}

int main() {
	int n, m;
	scanf("%d %d %d %s", &n, &m, &k, s);
	
	build_tree(1, n);
	
	for (int i = 0; i < m; i++) {
		int f;
		scanf("%d", &f);
		
		if (f == 1) {
			int l, r;
			char c;
			scanf("%d %d %c", &l, &r, &c);
			
			update(1, l, r, c - 'a');
		}
		else {
			scanf(" %s", s);
			
			int ans = 1;
			for (int i = 0; i < k; i++)
				for (int j = 0; j <= i; j++)
					ans += t[1].cnt[s[i] - 'a'][s[j] - 'a'];
			
			printf("%d\n", ans);
		}
	}
	
	return 0;
}