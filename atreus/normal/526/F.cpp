#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int n;
int a[maxn], b[maxn], c[maxn], premnm[maxn], premxm[maxn];

struct node{
	int mnm;
	int cntmnm;
	int lazy;
	node (int mnm_ = 0, int cntmnm_ = 0){
		mnm = mnm_;
		cntmnm = cntmnm_;
	}
} seg[4 * maxn];


void propagate(int, int, int);

node merge(node fi, node se){
	node ret;
	ret.mnm = min(fi.mnm, se.mnm);
	ret.cntmnm = (fi.mnm == ret.mnm) * fi.cntmnm + (se.mnm == ret.mnm) * se.cntmnm;
	return ret;
}

void add(int id, int L, int R, int l, int r, int val){
//	if (id == 1)
//		cout << l << " " << r << " -> " << val << endl;
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id].mnm += val;
		seg[id].lazy += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	add(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}

node get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return node(n + 1, 0);
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	propagate(id, L, R);
	return merge(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void build(int id, int L, int R){
	seg[id].cntmnm = R - L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		x --, y --;
		a[x] = y;
	}
	for (int i = 0; i < n; i++){
		premxm[i] = i - 1;
		while (premxm[i] != -1 and a[premxm[i]] < a[i])
			premxm[i] = premxm[premxm[i]];
		premnm[i] = i - 1;
		while (premnm[i] != -1 and a[premnm[i]] > a[i])
			premnm[i] = premnm[premnm[i]];
	}
	build(1, 0, n);
	ll answer = 0;
	for (int i = 0; i < n; i++){
		premxm[i] = i - 1;
		while (premxm[i] != -1 and a[premxm[i]] < a[i]){
			add(1, 0, n, premxm[i] + 1, i + 1, + a[premxm[i]] - b[i]);
			b[i] = a[premxm[i]];
			premxm[i] = premxm[premxm[i]];
		}
		add(1, 0, n, premxm[i] + 1, i + 1, + a[i] - b[i]);
		premnm[i] = i - 1;
		while (premnm[i] != -1 and a[premnm[i]] > a[i]){
			add(1, 0, n, premnm[i] + 1, i + 1, - a[premnm[i]] + c[i]);
			c[i] = a[premnm[i]];
			premnm[i] = premnm[premnm[i]];
		}
		add(1, 0, n, premnm[i] + 1, i + 1, - a[i] + c[i]);
		node T = get(1, 0, n, 0, i + 1);
		answer += (T.mnm == 0) * T.cntmnm;
		add(1, 0, n, 0, i + 1, -1);
	}
	cout << answer << endl;
}