# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100053;
const int INF = 0x3f3f3f3f;
int n, q;
char s[MAXN];
struct Matrix{
	int a[3][3];
	Matrix(int nm = 0){
		for (int i = 0; i <= 2; i++){
			for (int j = 0; j <= 2; j++){
				a[i][j] = nm;
			}
		}
	}
};
Matrix operator * (const Matrix &u, const Matrix &v){
	Matrix ans = Matrix(INF);
	for (int i = 0; i <= 2; i++){
		for (int k = 0; k <= 2; k++){
			for (int j = 0; j <= 2; j++){
				ans.a[i][j] = min(ans.a[i][j], u.a[i][k] + v.a[k][j]);
			}
		}
	}
	return ans;
}
Matrix bs[3];
struct SegTree{
	struct Node{
		Matrix s;
		int ls, rs;
	} t[MAXN * 4];
	int rt, tsz;
	void update(int nw){
		t[nw].s = t[t[nw].ls].s * t[t[nw].rs].s;
	}
	void build(int &nw, int lft, int rgt){
		nw = ++tsz;
		if (lft == rgt){
			t[nw].s = bs[s[lft] - 'a'];
			return;
		}
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
		update(nw);
	}
	void modify(int nw, int lft, int rgt, int pos, Matrix nm){
		if (lft == rgt){
			t[nw].s = nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, nm);
		else modify(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
} sgt;
int main(){
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++){
			if (j < i) bs[0].a[i][j] = bs[1].a[i][j] = bs[2].a[i][j] = INF;
			else if (i == j) bs[i].a[i][j] = 1;
		}
	}
	sgt.build(sgt.rt, 1, n);
	for (int i = 1; i <= q; i++){
		int u;
		char x;
		scanf("%d", &u);
		scanf(" %c", &x);
		sgt.modify(sgt.rt, 1, n, u, bs[x - 'a']);
		int ans = sgt.t[sgt.rt].s.a[0][2];
		printf("%d\n", ans);
	}
	return 0;
}