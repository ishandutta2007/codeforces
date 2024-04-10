# include <bits/stdc++.h>
# define ll long long
# define int long long
using namespace std;
const int MAXN = 50051;
struct Matrix{
	int a[2][2];
	Matrix(int a00 = 0, int a01 = 0, int a10 = 0, int a11 = 0){
		a[0][0] = a00;
		a[0][1] = a01;
		a[1][0] = a10;
		a[1][1] = a11;
	}
};
ll k;
int p, n, m, asz;
ll s[MAXN];
Matrix operator * (const Matrix &u, const Matrix &v){
	Matrix ans;
	for (int i = 0; i < 2; i++){
		for (int l = 0; l < 2; l++){
			for (int j = 0; j < 2; j++){
				ans.a[i][j] = (ans.a[i][j] + 1ll * u.a[i][l] * v.a[l][j]) % p;
			}
		}
	}
	return ans;
}
struct Node{
	ll pos;
	Matrix nm;
	Node(ll pos = 0, Matrix nm = Matrix()): pos(pos), nm(nm){}
} a[MAXN * 2];
bool cmp(Node u, Node v){
	return u.pos < v.pos;
}
struct SegTree{
	struct Node{
		Matrix s;
		int ls, rs;
	} t[MAXN * 3];
	int rt, tsz;
	void build(int &nw, int lft, int rgt){
		nw = ++tsz;
//		printf("build %d %d %d\n", nw, lft, rgt);
		if (lft == rgt){
			t[nw].s = Matrix(0, s[(lft - 2 + n * 2) % n], 1, s[(lft - 1 + n) % n]);
			return;
		}
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
		t[nw].s = t[t[nw].ls].s * t[t[nw].rs].s;
	}
	Matrix getsum(int nw, int lft, int rgt, int l, int r){
//		printf("getsum %d %d %d %d %d\n", nw, lft, rgt, l, r);
		if (l > r) return Matrix(1, 0, 0, 1);
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		Matrix ans = Matrix(1, 0, 0, 1);
		if (l <= mid) ans = ans * getsum(t[nw].ls, lft, mid, l, min(mid, r));
		if (r >= mid + 1) ans = ans * getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r);
		return ans;
	}
} sgt;
Matrix pwr(Matrix x, ll y){
	Matrix ans = Matrix(1, 0, 0, 1);
	while (y){
		if (y & 1) ans = ans * x;
		x = x * x;
		y >>= 1;
	}
	return ans;
}
signed main(){
	scanf("%lld%lld%lld", &k, &p, &n);
	if (k <= 1){
		printf("%lld\n", k % p);
		return 0;
	}
	for (int i = 0; i < n; i++){
		scanf("%lld", s + i);
		s[i] %= p;
	}
	sgt.build(sgt.rt, 0, n - 1);
	scanf("%lld", &m);
	for (int i = 0; i < m; i++){
		ll pos;
		int val;
		scanf("%lld%lld", &pos, &val);
		if (pos >= k) continue;
		val %= p;
		a[++asz] = Node(pos + 1, Matrix(0, s[(pos + n - 1) % n], 1, val));
		a[++asz] = Node(pos + 2, Matrix(0, val, 1, s[(pos + 1) % n]));
	}
	sort(a + 1, a + asz + 1, cmp);
	while (asz >= 1 && a[asz].pos > k) asz--;
	a[0].pos = 1;
	if (a[asz].pos < k) a[++asz] = Node(k, Matrix(0, s[(k - 2 + n * 2) % n], 1, s[(k - 1 + n) % n]));
	Matrix ans = Matrix(0, 1, 0, 0);
	for (int i = 1; i <= asz; i++){
		if (a[i].pos / n != a[i - 1].pos / n){
			ans = ans * sgt.getsum(sgt.rt, 0, n - 1, a[i - 1].pos % n + 1, n - 1);
			ans = ans * pwr(sgt.getsum(sgt.rt, 0, n - 1, 0, n - 1), a[i].pos / n - a[i - 1].pos / n - 1);
			ans = ans * sgt.getsum(sgt.rt, 0, n - 1, 0, a[i].pos % n - 1);
		} else ans = ans * sgt.getsum(sgt.rt, 0, n - 1, a[i - 1].pos % n + 1, a[i].pos % n - 1);
		if (a[i].pos == a[i + 1].pos){
			a[i].nm.a[0][1] ^= a[i + 1].nm.a[0][1] ^ s[(a[i].pos - 2 + 2 * n) % n];
			a[i].nm.a[1][1] ^= a[i + 1].nm.a[1][1] ^ s[(a[i].pos - 1 + 2 * n) % n];
			ans = ans * a[i].nm;
			i++;
		} else ans = ans * a[i].nm;
	}
	printf("%lld\n", (ans.a[0][1] % p + p) % p);
	return 0;
}