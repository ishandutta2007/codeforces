
// Problem : C. DZY Loves Fibonacci Numbers
// Contest : Codeforces - Codeforces Round #FF (Div. 1)
// URL : https://codeforces.com/contest/446/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, rng;
	long long sum;
	long long lzya, lzyb;
};

const long long MOD = 1e9+9, a = 691504013, b = 308495997, c = 276601605, invc = 383008016;
int N, M;
Node seg[2000000];
long long powsa[300005], powsb[300005];
long long geoa[300005], geob[300005];
long long arr[300005];

long long add(long long a, long long b){
	return (a+b) >= MOD ? a+b-MOD : a+b;
}

long long sub(long long a, long long b){
	return (a-b) < 0 ? a-b+MOD : a-b;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].rng = r - l + 1;
	if(seg[idx].l == seg[idx].r){
		seg[idx].sum = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].sum = add(seg[2*idx].sum, seg[2*idx+1].sum);
}

long long pd(int idx){
	if(seg[idx].lzya){
		seg[2*idx].sum = add(seg[2*idx].sum, mult(seg[idx].lzya, geoa[seg[2*idx].rng]));
		seg[2*idx].sum = sub(seg[2*idx].sum, mult(seg[idx].lzyb, geob[seg[2*idx].rng]));
		seg[2*idx].lzya = add(seg[2*idx].lzya, seg[idx].lzya);
		seg[2*idx].lzyb = add(seg[2*idx].lzyb, seg[idx].lzyb);
		seg[idx].lzya = mult(seg[idx].lzya, powsa[seg[2*idx].rng]);
		seg[idx].lzyb = mult(seg[idx].lzyb, powsb[seg[2*idx].rng]);
		seg[2*idx+1].sum = add(seg[2*idx+1].sum, mult(seg[idx].lzya, geoa[seg[2*idx+1].rng]));	
		seg[2*idx+1].sum = sub(seg[2*idx+1].sum, mult(seg[idx].lzyb, geob[seg[2*idx+1].rng]));
		seg[2*idx+1].lzya = add(seg[2*idx+1].lzya, seg[idx].lzya);
		seg[2*idx+1].lzyb = add(seg[2*idx+1].lzyb, seg[idx].lzyb);
		seg[idx].lzya = seg[idx].lzyb = 0;
	}
}

void upd(int l, int r, long long u, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].sum = add(seg[idx].sum, mult(u, geoa[seg[idx].rng]));
		seg[idx].sum = sub(seg[idx].sum, mult(v, geob[seg[idx].rng]));
		seg[idx].lzya = add(seg[idx].lzya, u);
		seg[idx].lzyb = add(seg[idx].lzyb, v);
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, u, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, u, v, 2*idx+1);
	}
	else{
		upd(l, mid, u, v, 2*idx);
		upd(mid+1, r, mult(u, powsa[mid - l + 1]), mult(v, powsb[mid - l + 1]), 2*idx+1);
	}
	seg[idx].sum = add(seg[2*idx].sum, seg[2*idx+1].sum);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].sum;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	powsa[0] = powsb[0] = 1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] = mult(arr[i], invc);
		powsa[i] = mult(powsa[i-1], a);
		powsb[i] = mult(powsb[i-1], b);
		geoa[i] = add(geoa[i-1], powsa[i-1]);
		geob[i] = add(geob[i-1], powsb[i-1]);
	}
	build(1, N, 1);
	while(M--){
		int cmd, l, r;
		cin >> cmd >> l >> r;
		if(cmd == 1){
			upd(l, r, a, b, 1);
		}
		else{
			cout << mult(query(l, r, 1), c) << "\n";
		}
	}
}