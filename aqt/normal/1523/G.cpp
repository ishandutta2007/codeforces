
// Problem : G. Try Booking
// Contest : Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1523/problem/G
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int oo = INT_MAX / 2;

struct SmallNode{
	int mn;	
	SmallNode * lft, * rht;	

	SmallNode(){
		mn = oo;
		lft = rht = NULL;
	}
};

struct BigNode{
	int l, r;
	SmallNode * n;	
};

int N, M;
BigNode seg[50005 * 4];
int s[100005], e[100005];
vector<pair<int, int>> qu;
int ans[100005];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].n = NULL;
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * idx);
	build(mid + 1, r, 2 * idx + 1);
}

SmallNode * upd(int l, int r, int p, int v, SmallNode * n){
	if(!n){
		n = new SmallNode();
	}
	n->mn = min(n->mn, v);
	if(l == r){
		return n;
	}
	int mid = (l + r)/2;
	if(p <= mid){
		n->lft = upd(l, mid, p, v, n->lft);
	}
	else{
		n->rht = upd(mid+1, r, p, v, n->rht);
	}
	return n;
}

void upd(int bp, int sp, int v, int idx){
	assert(seg[idx].l <= sp);
	seg[idx].n = upd(seg[idx].l, N, sp, v, seg[idx].n);
	if(seg[idx].l == seg[idx].r){
		return;
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(bp <= mid){
		upd(bp, sp, v, 2 * idx);
	}
	else{
		upd(bp, sp, v, 2 * idx + 1);
	}
}

int query(int l, int r, int ql, int qr, SmallNode * n){
	if(!n){
		return oo;
	}
	if(l == ql && r == qr){
		return n->mn;
	}
	int mid = (l + r) / 2;
	if(qr <= mid){
		return query(l, mid, ql, qr, n->lft);
	}
	else if(ql > mid){
		return query(mid+1, r, ql, qr, n->rht);
	}
	else{
		return min(query(l, mid, ql, mid, n->lft), query(mid+1, r, mid+1, qr, n->rht));
	}
}

int query(int bl, int br, int sl, int sr, int idx){
	if(seg[idx].l == bl && seg[idx].r == br){
		return query(seg[idx].l, N, max(sl, seg[idx].l), sr, seg[idx].n);
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(br <= mid){
		return query(bl, br, sl, sr, 2 * idx);
	}
	else if(bl > mid){
		return query(bl, br, sl, sr, 2 * idx + 1);
	}
	else{
		return min(query(bl, mid, sl, sr, 2 * idx), query(mid + 1, br, sl, sr, 2 * idx + 1));
	}
}

int solve(int l, int r){
	if(l > r){
		return 0;
	}
	int idx = query(l, r, l, r, 1);
	if(idx == oo){
		return 0;
	}
	return e[idx] - s[idx] + 1 + solve(l, s[idx] - 1) + solve(e[idx] + 1, r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		cin >> s[i] >> e[i];
		qu.emplace_back(e[i] - s[i] + 1, i);
	}
	build(1, N, 1);
	sort(qu.begin(), qu.end(), [](auto p, auto q){
		return p.first > q.first;
	});
	int idx = 0;
	for(int k = N; k; k--){
		while(idx != M && qu[idx].first == k){
			int i = qu[idx++].second;
			upd(s[i], e[i], i, 1);
		}
		ans[k] = solve(1, N);
	}
	for(int k = 1; k <= N; k++){
		cout << ans[k] << "\n";
	}
}