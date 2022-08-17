#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define INF 10000000000

int N;

void build_max(int seg[], int arr[], int id = 1, int l = 0, int r = N-1) {
	if(l == r) {
		seg[id] = arr[l];
		return;
	}
	
	int m = (l+r)/2;
	build_max(seg, arr, 2*id, l, m);
	build_max(seg, arr, 2*id+1, m+1, r);
	seg[id] = std::max(seg[2*id], seg[2*id+1]);
}

void build_min(int seg[], int arr[], int id = 1, int l = 0, int r = N-1) {
	if(l == r) {
		seg[id] = arr[l];
		return;
	}
	
	int m = (l+r)/2;
	build_min(seg, arr, 2*id, l, m);
	build_min(seg, arr, 2*id+1, m+1, r);
	seg[id] = std::min(seg[2*id], seg[2*id+1]);
}

int max(int seg[], int x, int y, int id = 1, int l = 0, int r = N-1) {
	if(r <= y && l >= x)
		return seg[id];
	
	if(y < l || x > r)
		return -1;
	
	int m = (l+r)/2;
	int a = max(seg, x, y, 2*id, l, m);
	int b = max(seg, x, y, 2*id+1, m+1, r);
	return std::max(a, b);
}

int min(int seg[], int x, int y, int id = 1, int l = 0, int r = N-1) {
	if(r <= y && l >= x)
		return seg[id];
	
	if(y < l || x > r)
		return INF;
	
	int m = (l+r)/2;
	int a = min(seg, x, y, 2*id, l, m);
	int b = min(seg, x, y, 2*id+1, m+1, r);
	return std::min(a, b);
}

signed main() {
	int n;
	std::cin >> n;
	
	N = 2*n;
	
	int reva[N], revb[N];
	std::vector<std::pair<int, int> > helpa;
	std::vector<std::pair<int, int> > helpb;
	for(int i = 0; i < n; i++) {
		int x, y, l, r;
		std::cin >> x >> y >> l >> r;
		helpa.push_back({x, i});
		helpa.push_back({y, i+n});
		helpb.push_back({l, i});
		helpb.push_back({r, i+n});
	}
	
	std::sort(helpa.begin(), helpa.end());
	std::sort(helpb.begin(), helpb.end());
	
	for(int i = 0; i < N; i++) {
		reva[helpa[i].second] = i;
		revb[helpb[i].second] = i;
	}
	
	int la[4*N+5], ra[4*N+5], lb[4*N+5], rb[4*N+5];
	
	int arr[N];
	
	for(int i = 0; i < N; i++) {
		int u = helpa[i].second;
		if(u >= n)
			u -= n;
		arr[i] = revb[u];
	}
	build_max(la, arr);
	
	for(int i = 0; i < N; i++) {
		int u = helpa[i].second;
		if(u >= n)
			u -= n;
		arr[i] = revb[u+n];
	}
	build_min(ra, arr);
	
	for(int i = 0; i < N; i++) {
		int u = helpb[i].second;
		if(u >= n)
			u -= n;
		arr[i] = reva[u];
	}
	build_max(lb, arr);
	
	for(int i = 0; i < N; i++) {
		int u = helpb[i].second;
		if(u >= n)
			u -= n;
		arr[i] = reva[u+n];
	}
	build_min(rb, arr);
	
	bool poss = true;
	for(int i = 0; i < n && poss; i++) {
		poss &= (max(la, reva[i], reva[i+n]) <= revb[i+n]);
		poss &= (min(ra, reva[i], reva[i+n]) >= revb[i]);
		poss &= (max(lb, revb[i], revb[i+n]) <= reva[i+n]);
		poss &= (min(rb, revb[i], revb[i+n]) >= reva[i]);
	}
	
	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";
	std::cout << std::endl;
	
	return 0;
}