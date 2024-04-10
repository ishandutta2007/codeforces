
// Problem : E. Sasha and a Very Easy Test
// Contest : Codeforces - Codeforces Round #539 (Div. 1)
// URL : https://codeforces.com/contest/1109/problem/E
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long val;
	long long lzyp;
	long long lzyr;
	long long re;
	vector<int> v;
	vector<int> lzyv;
};

int N, P;
const int M = 100000;
long long MOD;
int inv[100005];
int arr[100005];
int cnt[10][1000005];
int red[100005];
vector<int> pr;
node seg[1000000];

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

void pu(int idx){
	seg[idx].val = add(seg[2*idx].val, seg[2*idx+1].val);
	/*
	for(int k = 0; k<P; k++){
		seg[idx].v[k] = seg[2*idx].v[k] + seg[2*idx+1].v[k];
	}
	*/
}

void pd(int idx){
	if(seg[idx].lzyp != 1){
		seg[2*idx].lzyp = mult(seg[2*idx].lzyp, seg[idx].lzyp);
		seg[2*idx+1].lzyp = mult(seg[2*idx+1].lzyp, seg[idx].lzyp);
		seg[2*idx].val = mult(seg[2*idx].val, seg[idx].lzyp);
		seg[2*idx+1].val = mult(seg[2*idx+1].val, seg[idx].lzyp);
		seg[idx].lzyp = 1;
	}
	if(seg[idx].lzyr != 1){
		seg[2*idx].lzyr = mult(seg[2*idx].lzyr, seg[idx].lzyr);
		seg[2*idx+1].lzyr = mult(seg[2*idx+1].lzyr, seg[idx].lzyr);
		seg[2*idx].re = mult(seg[2*idx].re, seg[idx].lzyr);
		seg[2*idx+1].re = mult(seg[2*idx+1].re, seg[idx].lzyr);
		seg[idx].lzyr = 1;
	}
	for(int k = 0; k<P; k++){
		if(seg[idx].lzyv[k]){
			seg[2*idx].lzyv[k] += seg[idx].lzyv[k];
			seg[2*idx+1].lzyv[k] += seg[idx].lzyv[k];
			seg[2*idx].v[k] += seg[idx].lzyv[k];
			seg[2*idx+1].v[k] += seg[idx].lzyv[k];
			seg[idx].lzyv[k] = 0;
		}
	}
}

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	seg[idx].lzyv.resize(P);
	seg[idx].v.resize(P);
	seg[idx].lzyr = seg[idx].lzyp = 1;
	if(l == r){
		seg[idx].val = arr[l]%MOD;
		seg[idx].re = red[arr[l]]%MOD;
		for(int k = 0; k<P; k++){
			seg[idx].v[k] = (cnt[k][arr[l]]);
		}
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	pu(idx);
}

void upd(int l, int r, int v, int idx){
	//cout << seg[idx].l << " " << seg[idx].r << " " << l << " " << r << endl;
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].val = mult(seg[idx].val, v);
		seg[idx].re = mult(seg[idx].re, red[v]);
		seg[idx].lzyp = mult(seg[idx].lzyp, v);
		seg[idx].lzyr = mult(seg[idx].lzyr, red[v]);
		for(int k = 0; k<P; k++){
			//cout << cnt[k][arr[l]] << "\n";
			seg[idx].v[k] += cnt[k][v];
			seg[idx].lzyv[k] += cnt[k][v];
		}
		//cout << seg[idx].val << endl;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	pu(idx);
	//cout << seg[idx].val << endl;
}

void div(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r ){
		seg[idx].re = mult(seg[idx].re, inv[red[v]]);
		seg[idx].val = seg[idx].re;
		for(int k = 0; k<P; k++){
			seg[idx].v[k] -= cnt[k][v];
			seg[idx].val = mult(seg[idx].val, qikpow(pr[k], seg[idx].v[k]));
			//cout << cnt[k][v] << " " << seg[idx].v[k] << "\n";
		}
		//cout << " " << seg[idx].val << "\n";
		return;
	}
	pd(idx);
	if(p <= seg[idx].l + seg[idx].r >> 1){
		div(p, v, 2*idx);
	}
	else{
		div(p, v, 2*idx+1);
	}
	pu(idx);
	//cout << " " << seg[idx].val << "\n";
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].val;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return add(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> MOD;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	long long T = MOD;
	long long totient = MOD;
	for(int p = 2; p<=sqrt(T); p++){
		if(T%p == 0){
			pr.push_back(p);
			totient /= p;
			totient *= p-1;
			while(T%p == 0){
				T /= p;
			}
		}
	}
	if(T != 1){
		totient /= T;
		totient *= T-1;
		pr.push_back(T);
	}
	P = pr.size();
	for(int i = 1; i<=M; i++){
		red[i] = i;
		if(__gcd(1LL*i, MOD) == 1){
			inv[i] = qikpow(i, totient-1);
		}
	}
	for(int i = 0; i<P; i++){
		int p = pr[i];
		for(long long k = p; k<=M; k *= p){
			for(int s = k; s<=M; s += k){
				cnt[i][s]++;
				red[s] /= p;
			}
		}
	}
	build(1, N, 1);
	int Q;
	cin >> Q;
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int l, r, v;
			cin >> l >> r >> v;
			upd(l, r, v, 1);
		}
		else if(c == 2){
			int p, x;
			cin >> p >> x;
			div(p, x, 1);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(l, r, 1) << "\n";
		}
	}
}