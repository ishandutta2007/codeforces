#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 1e18 + N;
int n, q, ans = 0;

vector <pair <long long, int> > seg[N * 4];
long long a[N], b[N];

long long dcl(long long x, int y) {
    long long ans = x / y;
    if (x % y > 0) {
        ans++;
    }
    return ans;
}

long long inter(int h1, long long m1, int h2, long long m2) {
	if (h1 == h2) {
		if (m2 > m1) {
			return inf;
		}
		else {
			return -inf;
		}
	}
    return dcl(m2 - m1, h1 - h2);
}

void add_hull(int id, int i, int h, long long m) {
    while (seg[id].size() && inter(h, m, b[seg[id].back().second], a[seg[id].back().second]) <= seg[id].back().first) {
        seg[id].pop_back();
    }
    if (seg[id].size()) {
        seg[id].push_back({max(inter(h, m, b[seg[id].back().second], a[seg[id].back().second]), seg[id].back().first), i});
    }
    else {
    	seg[id].push_back({-inf, i});
	}
    
}

int get_hull(int id, int k) {
	pair <long long, int> p = {k, N};
	int x = upper_bound(seg[id].begin(), seg[id].end(), p) - seg[id].begin() - 1;
//	cout << "71 " << x << endl;
	return seg[id][x].second;
}

void build(int id = 1, int s = 0, int e = n) {
	if (e - s > 1) {
		int md = (s + e) / 2;
		build(id * 2, s, md);
		build(id * 2 + 1, md, e);
	}
	vector <pair <int, int> > vec;
	for (int i = s; i < e; i++) {
		vec.push_back({b[i], i});
	}
	sort(vec.begin(), vec.end());
	for (auto p : vec) {
		add_hull(id, p.second, b[p.second], a[p.second]);
	}
//	cout << "71 " << id << " " << seg[id].size() << endl;
//	for (auto p : seg[id]) {
//		cout << "72 " << p.first << " " << p.second << endl;
//	}

}

void get(int l, int r, int k, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		int v = get_hull(id, k);
		if (b[v] * k + a[v] > b[ans] * k + a[ans]) {
			ans = v;
		}
		return;
	}
	int md = (s + e) / 2;
	get(l, r, k, id * 2, s, md);
	get(l, r, k, id * 2 + 1, md, e);
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    build();
	for (int ii = 0; ii < q; ii++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		ans = l;
		get(l, r, k);
		cout << ans + 1 << '\n';
	}
}