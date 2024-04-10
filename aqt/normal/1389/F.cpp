
// Problem : F. Bicolored Segments
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree{
	struct Node{
		int l, r;
		int mx, lzy;
	};
	Node seg[2000000];
	
	void build(int l, int r, int idx){
		seg[idx].l = l, seg[idx].r = r;
		if(l == r){
			return;
		}
		int mid = l+r>>1;
		build(l, mid, 2*idx);
		build(mid+1, r, 2*idx+1);
	}
	void pd(int idx){
		if(seg[idx].lzy){
			seg[2*idx].lzy += seg[idx].lzy;
			seg[2*idx+1].lzy += seg[idx].lzy;
			seg[2*idx].mx += seg[idx].lzy;
			seg[2*idx+1].mx += seg[idx].lzy;
			seg[idx].lzy = 0;
		}
	}	
	void upd(int l, int r, int v, int idx){
		if(seg[idx].l == l && seg[idx].r == r){
			seg[idx].mx += v;
			seg[idx].lzy += v;
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
		seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
	}
	void st(int p, int v, int idx){
		if(seg[idx].l == seg[idx].r){
			seg[idx].mx = max(seg[idx].mx, v);
			return;
		}
		pd(idx);
		int mid = seg[idx].l + seg[idx].r >> 1;
		if(p <= mid){
			st(p, v, 2*idx);
		}
		else{
			st(p, v, 2*idx+1);
		}
		seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
	}
	
} tree[2];

int N;
const int oo = INT_MAX/2;
vector<int> cmp[2];
pair<pair<int, int>, int> arr[200005];

int getidx(int t, int n){
	return upper_bound(cmp[t].begin(), cmp[t].end(), n) - cmp[t].begin();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int l, r, t;
		cin >> l >> r >> t;
		cmp[(t == 1 ? 0 : 1)].push_back(l);
		cmp[(t == 1 ? 0 : 1)].push_back(r);
		arr[i].first = make_pair(r, l);
		arr[i].second = (t == 1 ? 0 : 1);
	}
	cmp[0].push_back(0);
	cmp[1].push_back(0);
	sort(cmp[0].begin(), cmp[0].end());
	sort(cmp[1].begin(), cmp[1].end());
	cmp[0].erase(unique(cmp[0].begin(), cmp[0].end()), cmp[0].end());
	cmp[1].erase(unique(cmp[1].begin(), cmp[1].end()), cmp[1].end());
	int ans = 0;
	sort(arr+1, arr+1+N);
	tree[0].build(1, cmp[0].size(), 1);
	tree[1].build(1, cmp[1].size(), 1);
	for(int i = 1; i<=N; i++){
		swap(arr[i].first.second, arr[i].first.first);
		int rhtidx = getidx(arr[i].second, arr[i].first.second);
		int lftidx = getidx(arr[i].second^1, arr[i].first.first-1);
		tree[arr[i].second^1].upd(1, lftidx, 1, 1);
		int v = tree[arr[i].second^1].seg[1].mx;
		tree[arr[i].second].st(rhtidx, v, 1);
		ans = max(ans, v);
	}
	cout << ans << "\n";
}