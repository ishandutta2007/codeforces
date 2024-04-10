
// Problem : F. Swapping Problem
// Contest : Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL : https://codeforces.com/contest/1513/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Event{
	int x, y, t;
	
	bool operator < (const Event e) const{
		return e.x < x;
	}
};

const long long inf = LLONG_MAX / 10;

struct SegmentTree{
	struct Node{
		int l, r;
		long long mn;
	};
	
	Node seg[4 * 200005];
	
	void build(int l, int r, int idx){
		seg[idx].l = l;
		seg[idx].r = r;
		seg[idx].mn = inf;
		if(l == r){
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, 2 * idx);
		build(mid + 1, r, 2 * idx + 1);
	}
	
	void upd(int p, long long v, int idx){
		if(seg[idx].l == seg[idx].r){
			seg[idx].mn = v;
			return;
		}
		int mid = (seg[idx].l + seg[idx].r) / 2;
		if(p <= mid){
			upd(p, v, 2 * idx);
		}
		else{
			upd(p, v, 2 * idx + 1);
		}
		seg[idx].mn = min(seg[2 * idx].mn, seg[2 * idx + 1].mn);
	}
	
	long long query(int l, int r, int idx){
		if(seg[idx].l == l && seg[idx].r == r){
			return seg[idx].mn;
		}
		int mid = (seg[idx].l + seg[idx].r) / 2;
		if(r <= mid){
			return query(l, r, 2 * idx);
		}
		else if(l > mid){
			return query(l, r, 2 * idx + 1);
		}
		else{
			return min(query(l, mid, 2 * idx), query(mid + 1, r, 2 * idx + 1));
		}
	}
};

int N;
int arr[200005];
int brr[200005];
pair<int, int> srtb[200005];
SegmentTree toplftseg;
SegmentTree toprhtseg;
SegmentTree botlftseg;
SegmentTree botrhtseg;
priority_queue<Event> pq;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long tot = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> brr[i];
		srtb[i] = make_pair(brr[i], arr[i]);
	}
	sort(srtb + 1, srtb + 1 + N);
	toplftseg.build(1, N, 1);
	toprhtseg.build(1, N, 1);
	botlftseg.build(1, N, 1);
	botrhtseg.build(1, N, 1);
	for(int i = 1; i <= N; i++){
		pq.push({arr[i], brr[i], 1});
		pq.push({brr[i], arr[i], 0});
		long long d = abs(arr[i] - brr[i]);
		tot += d;
		int k = lower_bound(srtb + 1, srtb + 1 + N, make_pair(brr[i], arr[i])) - srtb;
		toprhtseg.upd(k, arr[i] + brr[i] - d, 1);
		botrhtseg.upd(k, arr[i] - brr[i] - d, 1);
	}
	long long ans = tot;
	while(pq.size()){
		auto p = pq.top();
		pq.pop();
		if(p.t){
			int k = lower_bound(srtb + 1, srtb + 1 + N, make_pair(p.y, p.x)) - srtb;
			long long d = abs(p.x - p.y);
			toprhtseg.upd(k, inf, 1);
			botrhtseg.upd(k, inf, 1);
			toplftseg.upd(k, - p.x + p.y - d, 1);
			botlftseg.upd(k, - p.x - p.y - d, 1);
		}
		else{
			int k = lower_bound(srtb + 1, srtb + 1 + N, make_pair(p.y, 0)) - srtb;
			long long d = abs(p.x - p.y);
			if(k != 1){
				ans = min(ans, tot + botlftseg.query(1, k - 1, 1) + p.x + p.y - d);
				ans = min(ans, tot + botrhtseg.query(1, k - 1, 1) - p.x + p.y - d);
			}
			if(k != N + 1){
				ans = min(ans, tot + toplftseg.query(k, N, 1) + p.x - p.y - d);
				ans = min(ans, tot + toprhtseg.query(k, N, 1) - p.x - p.y - d);
			}
		}
	}
	cout << ans;
}