
// Problem : F. Telepanting
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long lzy;
	long long cnt;
};

int N;
int lft[400005], rht[400005], s[400005];
Node seg[4 * 400005];
const long long MOD = 998244353;
vector<int> cmp;

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * idx);
	build(mid+1, r, 2 * idx + 1);
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2 * idx].lzy += seg[idx].lzy;
		seg[2 * idx].lzy %= MOD;
		seg[2 * idx].cnt += seg[idx].lzy;
		seg[2 * idx].cnt %= MOD;
		seg[2 * idx + 1].lzy += seg[idx].lzy;
		seg[2 * idx + 1].lzy %= MOD;
		seg[2 * idx + 1].cnt += seg[idx].lzy;
		seg[2 * idx + 1].cnt %= MOD;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].cnt += v;
		seg[idx].lzy %= MOD;
		seg[idx].cnt %= MOD;
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		upd(l, r, v, 2 * idx);
	}
	else if(l > mid){
		upd(l, r, v, 2 * idx + 1);
	}
	else{
		upd(l, mid, v, 2 * idx);
		upd(mid+1, r, v, 2 * idx + 1);
	}
}

int query(int p, int idx){
	if(seg[idx].l == seg[idx].r){
		return seg[idx].cnt;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(p <= mid){
		return query(p, 2 * idx);
	}
	else{
		return query(p, 2 * idx + 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> rht[i] >> lft[i] >> s[i];
		cmp.emplace_back(lft[i]);
		cmp.emplace_back(rht[i]);
	}
	sort(cmp.begin(), cmp.end());
	build(1, 2 * N, 1);
	long long ans = rht[N] + 1;
	for(int i = N; i; i--){
		int lftidx = upper_bound(cmp.begin(), cmp.end(), lft[i]) - cmp.begin();
		int rhtidx = upper_bound(cmp.begin(), cmp.end(), rht[i]) - cmp.begin();
		long long tot = (query(rhtidx, 1) + s[i])%MOD;
		ans += tot * (rht[i] - lft[i]) % MOD;
		ans %= MOD;
		upd(lftidx, rhtidx, tot, 1);
	}
	cout << ans;
}