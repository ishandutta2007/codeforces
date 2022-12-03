#include <bits/stdc++.h>

using namespace std;
int n, k;
vector< tuple<int, int, int, int> > g[10100];
int f[100100], x[100100], r[100100];

const int maxn = (int)3e5 + 200;
int t[3][4 * maxn];


int get(int id, int v, int tl, int tr, int l, int r) {
	if(tl > r || l > tr) return 0;
	if(l <= tl && tr <= r) return t[id][v];
	int mid = (tl + tr)/2;
	return get(id, 2 * v, tl, mid, l, r) + get(id, v * 2 + 1, mid+1, tr, l, r);
}
void upd(int id, int v, int tl, int tr, int pos, int val) {
	if(tl == tr) {
		t[id][v] += val;
	} else {
		int mid = (tl + tr)/2;
		if(pos <= mid) upd(id, v * 2, tl, mid, pos, val);
		else upd(id, v * 2 + 1, mid+1, tr, pos, val);
		t[id][v] = t[id][v * 2] + t[id][v * 2 + 1];
	}
}


long long calc(vector< tuple<int, int, int, int> > &a, vector< tuple<int, int, int, int> > &b) {
	if(a.size()==0 || b.size()==0) return 0;
	int j = 0;
	long long ans = 0;
	for(int i = 0; i < a.size(); i++) {
		while(j < b.size() && get<0>(b[j]) > get<0>(a[i])) {
			int pos = get<1>(b[j]);
			int l = get<2>(b[j]);
			int r = get<3>(b[j]);
			ans += get(0, 1, 0, maxn-1, l, r);
			upd(1, 1, 0, maxn-1, pos, 1);
			j++;
		}
		int pos = get<1>(a[i]);
		int l = get<2>(a[i]);
		int r = get<3>(a[i]);
		ans += get(1, 1, 0, maxn-1, l, r);
		upd(0, 1, 0, maxn-1, pos, 1);
	}
	while(j < b.size()) {
		int pos = get<1>(b[j]);
		int l = get<2>(b[j]);
		int r = get<3>(b[j]);
		ans += get(0, 1, 0, maxn-1, l, r);
		upd(1, 1, 0, maxn-1, pos, 1);
		j++;
	}
	for(int i = 0; i < a.size(); i++) {
		int pos = get<1>(a[i]);
		upd(0, 1, 0, maxn-1, pos, -1);
	}
	for(int i = 0; i < b.size(); i++) {
		int pos = get<1>(b[i]);
		upd(1, 1, 0, maxn-1, pos, -1);
	}
	return ans;
}
int main() {
	cin >> n >> k;
	vector<int> pos;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> r[i] >> f[i];
		pos.push_back(x[i]);
		pos.push_back(x[i]-r[i]);
		pos.push_back(x[i]+r[i]);
	}
	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
	for(int i = 0; i < n; i++) {
		int a = lower_bound(pos.begin(), pos.end(), x[i]) - pos.begin();
		int b = lower_bound(pos.begin(), pos.end(), x[i]-r[i]) - pos.begin();
		int c = lower_bound(pos.begin(), pos.end(), x[i]+r[i]) - pos.begin();
		g[f[i]].push_back({r[i], a, b, c});
	}
	long long ans = 0;
	for(int i = 0; i < 10100; i++) {
		if(g[i].size() == 0) continue;
		sort(g[i].begin(), g[i].end());
		reverse(g[i].begin(), g[i].end());
		for(int j = 1; j <= k && i - j >= 0; j++) {
			if(g[i-j].size() == 0) continue;
			ans += calc(g[i-j], g[i]);
			//cout << i - j << " "<< i << " " << calc(g[i-j], g[j]) << "\n";
		}

		ans += (calc(g[i], g[i]) - g[i].size())/2;
	}
	cout << ans << "\n";
	return 0;
}