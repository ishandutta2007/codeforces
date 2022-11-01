#include <bits/stdc++.h>

using namespace std;

struct segTree {
	int n;
	vector<vector<int>> tr;
	segTree(vector<int> &a) {
		n = a.size();
		tr.resize(2 * n);
		for(int i = 0; i < n; i++)
			tr[i + n].push_back(a[i]);
		for(int i = n - 1; i > 0; i--)
			merge(tr[i*2].begin(), tr[i*2].end(), tr[i*2+1].begin(), tr[i*2+1].end(), back_inserter(tr[i]));
	}
	int query(int v, int x) {
		int sz = tr[v].size();
		if(x > tr[v][sz - 1])
			return 0;
		int l = 0, r = sz - 1;
		while(l < r) {
			int m = (l + r) >> 1;
			if(tr[v][m] >= x)
				r = m;
			else
				l = m + 1;
		}
		return sz - l;
	}
	int query(int l, int r, int x) { // >= x
		int res = 0;
		for(l += n, r += n; l <= r; l = (l+1)>>1, r = (r-1)>>1) {
			if(l&1) res += query(l, x);
			if(!(r&1)) res += query(r, x);
		}
		return res;
	}
};

struct state {
	int first, second, idx;
	state() {}
	bool operator < (const state &x) const {
		return first < x.first || first == x.first && second < x.second;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<state> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].idx = i;
	}
	sort(a.begin(), a.end());
	vector<int> b(n);
	for(int i = 0; i < n; i++)
		b[i] = a[i].second;
	segTree tr(b);
	vector<int> far(n);
	int best = -1;
	for(int i = 0; i < n; i++) {
		int l = a[i].first, r = 1000000000;
		while(l < r) {
			int m = (l + r) >> 1;
			if(l == m) m++;
			if(tr.query(0, i, m) >= k)
				l = m;
			else
				r = m - 1;
		}
		far[i] = l;
		if(tr.query(0, i, far[i]) >= k && (best == -1 || far[i] - a[i].first > far[best] - a[best].first))
			best = i;
	}
	if(best == -1 || tr.query(0, best, far[best]) < k) {
		cout << "0\n";
		for(int i = 0; i < k; i++)
			cout << a[i].idx + 1 << ' ';
		return 0;
	}
	cout << far[best] - a[best].first + 1 << "\n";
	for(int i = 0; i < n && k > 0; i++)
		if(a[i].first <= a[best].first && far[best] <= a[i].second) {
			cout << a[i].idx + 1 << ' '; k--;
		}
}