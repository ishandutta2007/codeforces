#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

struct matrix{
	int n, m;
	int a[2][2];
	matrix(int n_ = 1, int m_ = 2){
		n = n_, m = m_;
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}
	matrix operator * (const matrix &b){
		matrix ret = matrix(n, b.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < b.m; j++)
				for (int k = 0; k < m; k++)
					ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][k] * b.a[k][j]) % mod;
		return ret;
	}
	matrix operator + (const matrix &b){
		matrix ret = matrix(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				ret.a[i][j] = (a[i][j] + b.a[i][j]);
				if (ret.a[i][j] >= mod)
					ret.a[i][j] -= mod;
			}
		return ret;
	}
} fib;

matrix power(matrix a, ll b){
	if (b == 1)
		return a;
	matrix ret = power(a, b/2);
	ret = ret * ret;
	if (b & 1)
		ret = ret * a;
	return ret;
}

matrix seg[4*maxn], lazy[4*maxn];

void shift(int,int,int);

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id].a[0][0];
	shift(id, L, R);
	int mid = (L + R) >> 1;
	int fi = get(2*id+0, L, mid, l, r);
	int se = get(2*id+1, mid, R, l, r);
	int ret = fi + se;
	if (ret >= mod)
		ret -= mod;
	return ret;
}

matrix tmp;

void add(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		lazy[id] = lazy[id] * tmp;
		seg[id] = seg[id] * tmp;
		return;
	}
	shift(id, L, R);
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, l, r);
	add(2*id+1, mid, R, l, r);
	seg[id] = seg[2*id+0] + seg[2*id+1];
}

void shift(int id, int L, int R){
	seg[2*id+0] = seg[2*id+0] * lazy[id];
	seg[2*id+1] = seg[2*id+1] * lazy[id];
	lazy[2*id+0] = lazy[2*id+0] * lazy[id];
	lazy[2*id+1] = lazy[2*id+1] * lazy[id];
	lazy[id].a[0][0] = lazy[id].a[1][1] = 1;
	lazy[id].a[0][1] = lazy[id].a[1][0] = 0;
}

void build(int id, int L, int R){
	lazy[id] = matrix(2, 2);
	lazy[id].a[0][0] = lazy[id].a[1][1] = 1;
	if (L + 1 == R){
		seg[id].a[0][0] = 1, seg[id].a[0][1] = 0;
		return;
	}
	int mid = (L + R) >> 1;
	build(2*id+0, L, mid);
	build(2*id+1, mid, R);
	seg[id] = seg[2*id+0] + seg[2*id+1];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	fib = matrix(2, 2);
	fib.a[0][0] = fib.a[0][1] = fib.a[1][0] = 1;
	fib.a[1][1] = 0;
	build(1, 0, n);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x > 1){
			tmp = power(fib, x-1);
			add(1, 0, n, i, i+1);
		}
	}
	while (m --){
		int type;
		cin >> type;
		if (type == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			tmp = power(fib, x);
			add(1, 0, n, l, r); 
		}
		else{
			int l, r;
			cin >> l >> r;
			l--;
			cout << get(1, 0, n, l, r) << '\n';
		}
	}
}