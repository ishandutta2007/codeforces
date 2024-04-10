
// Problem : F. Reverse and Swap
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	long long sum;
	int dep;
};

int N, Q;
Node seg[1000000];
long long arr[1000000];
bool rev[20];

void build(int l, int r, int idx){
	seg[idx].dep = 31 - __builtin_clz(r-l+1);
	if(l == r){
		seg[idx].sum = arr[l];
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

void upd(int p, int v, int idx){
	if(seg[idx].dep == 0){
		seg[idx].sum = v;
		return;
	}
	int half = (1<<(seg[idx].dep-1));
	if(p >= half){
		upd(p-half, v, 2*idx+(1^rev[seg[idx].dep]));
	}
	else{
		upd(p, v, 2*idx+(rev[seg[idx].dep]));
	}
	seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

long long query(int l, int r, int idx){
	if(l+(1<<seg[idx].dep) - 1 == r){
		return seg[idx].sum;
	}
	int half = (1<<(seg[idx].dep-1));
	if(r < half){
		return query(l, r, 2*idx+rev[seg[idx].dep]);
	}
	else if(l >= half){
		return query(l-half, r-half, 2*idx+(1^rev[seg[idx].dep]));
	}
	else{
		return query(l, half-1, 2*idx+rev[seg[idx].dep]) + query(0, r-half, 2*idx+(1^rev[seg[idx].dep]));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 0; i<1<<N; i++){
		cin >> arr[i];
	}
	build(0, (1<<N)-1, 1);
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int p, x;
			cin >> p >> x;
			p--;
			arr[p] = x;
			upd(p, x, 1);
		}
		else if(c == 2){
			int k;
			cin >> k;
			for(int i = k; i>=0; i--){
				rev[i] ^= 1;
			}
		}
		else if(c == 3){
			int k;
			cin >> k;
			rev[1+k] ^= 1;
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			cout << query(l, r, 1) << "\n";
		}
	}
}