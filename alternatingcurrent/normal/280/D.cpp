#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

const int MAXK = 21;

void merge_dp(int *a, int *b, int *t){
	int nval = a[0] + b[0], cur = 0;
	t[cur++] = nval;
	for(int i = 0, j = 0; cur <= MAXK; ){
		if(a[i+1] - a[i] >= b[j+1] - b[j])
			t[cur++] = (nval += a[i+1] - a[i]), i++;
		else
			t[cur++] = (nval += b[j+1] - b[j]), j++;
	}
}
void merge_dat(int (*l)[24], int (*r)[24], int (*t)[24]){
	static int tmp[MAXK+3];
	
	merge_dp(l[0], r[0], t[0]);
	merge_dp(l[2], r[1], tmp);
	rep(i, MAXK) t[0][i] = max(t[0][i], tmp[i+1]);
	
	merge_dp(l[1], r[0], t[1]);
	merge_dp(l[3], r[1], tmp);
	rep(i, MAXK) t[1][i] = max(t[1][i], tmp[i+1]);
	
	merge_dp(l[0], r[2], t[2]);
	merge_dp(l[2], r[3], tmp);
	rep(i, MAXK) t[2][i] = max(t[2][i], tmp[i+1]);
	
	merge_dp(l[1], r[2], t[3]);
	merge_dp(l[3], r[3], tmp);
	rep(i, MAXK) t[3][i] = max(t[3][i], tmp[i+1]);
	
	rep(i, MAXK)
		t[1][i] = max(t[1][i], t[3][i]), t[2][i] = max(t[2][i], t[3][i]), t[0][i] = max({t[0][i], t[1][i], t[2][i]});
}
namespace segt{
	const int MAXCN = 1 << 18;
	int dat[MAXCN+3][4][MAXK+3];
	void pushup(int k){
		merge_dat(dat[k+k], dat[k+k+1], dat[k]);
	}
	void build(int *a, int l, int r, int k){
		dat[k][0][0] = 0, dat[k][1][0] = dat[k][2][0] = dat[k][3][0] = -100000000;
		if(l == r){
			for(int i = 1; i <= MAXK; ++i)
				dat[k][0][i] = max(0, a[l]), dat[k][1][i] = dat[k][2][i] = dat[k][3][i] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(a, l, mid, k+k), build(a, mid+1, r, k+k+1);
		pushup(k);
	}
	void update(int p, int v, int l, int r, int k){
		if(l == r){
			for(int i = 1; i <= MAXK; ++i)
				dat[k][0][i] = max(0, v), dat[k][1][i] = dat[k][2][i] = dat[k][3][i] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		if(p <= mid)
			update(p, v, l, mid, k+k);
		else
			update(p, v, mid+1, r, k+k+1);
		pushup(k);
	}
	int cur = 0;
	int tmp[100][4][MAXK+3];
	int query(int tl, int tr, int l, int r, int k){
		if(l > tr || tl > r)
			return -1;
		if(tl <= l && r <= tr){
			memcpy(tmp[cur], dat[k], sizeof(dat[k])); ++cur;
			return cur-1;
		}
		int mid = (l + r) >> 1;
		int lret = query(tl, tr, l, mid, k+k);
		int rret = query(tl, tr, mid+1, r, k+k+1);
		if(lret < 0) return rret;
		if(rret < 0) return lret;
		merge_dat(tmp[lret], tmp[rret], tmp[cur]);
		++cur;
		return cur-1;
	}
}

int n;
int a[100100];
int m;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) cin >> a[i];
	
	segt::build(a, 0, n-1, 1);
	
	cin >> m;
	while(m--){
		int tp;
		cin >> tp;
		if(tp == 0){
			int p, v;
			cin >> p >> v;
			--p;
			a[p] = v;
			segt::update(p, v, 0, n-1, 1);
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			--l, --r;
			segt::cur = 0;
			int retid = segt::query(l, r, 0, n-1, 1);
			cout << segt::tmp[retid][0][k] << "\n";
		}
	}
	return 0;
}