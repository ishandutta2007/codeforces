#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 3;
const int mod = 1e6 + 7;

struct node{
	ld dp;
	ld pd;
	node (ld dp_ = 0.0, ld pd_ = 0.0){
		dp = dp_;
		pd = pd_;
	}
};

ld p[maxn];
node seg[4 * maxn];

node merge(node v, node u){
	ld fi = v.dp * u.dp / (1. + (u.dp - 1) * v.pd);
	ld se = u.pd + ((1. - u.pd) * u.dp * v.pd) / (1. - v.pd * (1 - u.dp));
	return node(fi, se);
}

node get(int id, int L, int R, int l, int r){
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (r <= mid)
		return get(2 * id + 0, L, mid, l, r);
	if (mid <= l)
		return get(2 * id + 1, mid, R, l, r);
	return merge(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void add(int id, int L, int R, int idx){
	if (idx < L or R <= idx)
		return;
	if (L + 1 == R){
		seg[id].dp = p[idx];
		seg[id].pd = p[idx];
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, idx);
	add(2 * id + 1, mid, R, idx);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		p[i] = 1. * a / b;
		add(1, 0, n, i);
	}
	while (q --){
		int type;
		cin >> type;
		if (type == 1){
			int idx, a, b;
			cin >> idx >> a >> b;
			idx --;
			p[idx] = 1. * a / b;
			add(1, 0, n, idx);
		}
		else{
			int l, r;
			cin >> l >> r;
			l --;
			cout << fixed << setprecision(4) << get(1, 0, n, l, r).dp << '\n';
		}
	}
}