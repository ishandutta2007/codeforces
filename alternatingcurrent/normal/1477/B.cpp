#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, q;
string s, f;
int ql[200200], qr[200200];
int sum[800800], laz[800800], tag[800800];

void pushdown(int k, int l, int r){
	if(!laz[k]) return ;
	laz[k] = 0;
	laz[k+k] = 1;
	laz[k+k+1] = 1;
	tag[k+k] = tag[k];
	tag[k+k+1] = tag[k];
	int mid = (l + r) >> 1;
	sum[k+k] = tag[k] * (mid - l + 1);
	sum[k+k+1] = tag[k] * (r - mid);
	tag[k] = 0;
}

void update(int tl, int tr, int val, int l, int r, int k){
	if(tl > r || l > tr) return ;
	if(tl <= l && r <= tr){
		laz[k] = 1;
		tag[k] = val;
		sum[k] = val * (r - l + 1);
		return ;
	}
	pushdown(k, l, r);
	int mid = (l + r) >> 1;
	update(tl, tr, val, l, mid, k+k);
	update(tl, tr, val, mid+1, r, k+k+1);
	sum[k] = sum[k + k] + sum[k + k + 1];
}
int query(int tl, int tr, int l, int r, int k){
	if(tl > r || l > tr) return 0;
	if(tl <= l && r <= tr) return sum[k];
	pushdown(k, l, r);
	int mid = (l + r) >> 1;
	return query(tl, tr, l, mid, k+k) + query(tl, tr, mid+1, r, k+k+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> q;
		cin >> s >> f;
		rep(i, q) cin >> ql[i] >> qr[i];
		rep(i, q) ql[i]--, qr[i]--;
		rep(i, n) update(i, i, f[i] - '0', 0, n-1, 1);
		bool ok = 1;
		for(int i = q - 1; i >= 0; i--){
			int now = query(ql[i], qr[i], 0, n-1, 1);
			int target = (qr[i] - ql[i] + 1 + 1) / 2;
			if((qr[i] - ql[i]) % 2 == 1 && target == now){
				cout << "NO" << endl;
				ok = 0;
				break;
			}
			if(target > now) update(ql[i], qr[i], 0, 0, n-1, 1);
			else update(ql[i], qr[i], 1, 0, n-1, 1);
		}
		if(!ok) continue;
		rep(i, n) if(query(i, i, 0, n-1, 1) != s[i] - '0'){
			cout << "NO" << endl;
			ok = 0;
			break;
		}
		if(ok) cout << "YES" << endl;
	}
	return 0;
}