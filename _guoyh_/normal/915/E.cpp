# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 600051;
struct Tree{
	int s, tag;
	int lft, rgt, ls, rs;
} t[NR << 2];
int n, q, tsz;
int a[NR];
int nl[NR], nr[NR], nk[NR];
void update(int nw){
	t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
}
void push_down(int nw){
	if (!t[nw].tag) return;
	if (t[nw].tag == 2){
		t[t[nw].ls].s = a[t[t[nw].ls].rgt + 1] - a[t[t[nw].ls].lft];
		t[t[nw].rs].s = a[t[t[nw].rs].rgt + 1] - a[t[t[nw].rs].lft];
		t[t[nw].ls].tag = 2;
		t[t[nw].rs].tag = 2;
		t[nw].tag = 0;
	} else {
		t[t[nw].ls].s = 0;
		t[t[nw].rs].s = 0;
		t[t[nw].ls].tag = 1;
		t[t[nw].rs].tag = 1;
		t[nw].tag = 0;
	}
}
int build(int l, int r){
	int nw = ++tsz;
	t[nw].lft = l;
	t[nw].rgt = r;
	t[nw].tag = 0;
	if (l == r){
		t[nw].s = a[l + 1] - a[l];
		return nw;
	}
	int mid = (l + r) >> 1;
	t[nw].ls = build(l, mid);
	t[nw].rs = build(mid + 1, r);
	update(nw);
	return nw;
}
void modify(int nw, int l, int r, int x){
	// printf("modify %d %d %d %d %d\n", t[nw].lft, t[nw].rgt, l, r, x);
	if (t[nw].lft == l && t[nw].rgt == r){
		t[nw].tag = x;
		if (x == 1) t[nw].s = 0;
		else t[nw].s = a[t[nw].rgt + 1] - a[t[nw].lft];
		return;
	}
	push_down(nw);
	int mid = (t[nw].lft + t[nw].rgt) >> 1;
	if (l <= mid) modify(t[nw].ls, l, min(mid, r), x);
	if (r >= mid + 1) modify(t[nw].rs, max(l, mid + 1), r, x);
	update(nw);
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++){
		scanf("%d%d%d", nl + i, nr + i, nk + i);
		a[i * 2 - 1] = nl[i];
		a[i * 2] = nr[i] + 1;
	}
	sort(a + 1, a + 2 * q + 1);
	a[2 * q + 1] = n + 1;
	int sz = unique(a + 1, a + 2 * q + 2) - a - 1;
	// for (int i = 1; i <= sz; i++) printf("%d ", a[i]);
	// putchar('\n');
	build(1, sz - 1);
	// if (q == 100000) printf("%d\n", a[sz]);
	for (int i = 1; i <= q; i++){
		nl[i] = lower_bound(a + 1, a + sz + 1, nl[i]) - a;
		nr[i] = lower_bound(a + 1, a + sz + 1, nr[i] + 1) - a;
		modify(1, nl[i], nr[i] - 1, nk[i]);
		printf("%d\n", t[1].s + a[1] - 1);
	}
	return 0;
}