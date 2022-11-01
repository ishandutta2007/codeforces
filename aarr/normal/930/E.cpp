#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 400 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;
int n, m, k;

vector <int> vec;
int seg[2][N * 4];
bool lazy[2][N * 4];
vector <pair <int, int> > q[N];
int l[N];
int r[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
void shift(int sg, int id) {
	if (lazy[sg][id]) {
		lazy[sg][id * 2] = true;
		lazy[sg][id * 2 + 1] = true;
		seg[sg][id * 2] = 0;
		seg[sg][id * 2 + 1] = 0;
	}
}
void add(int sg, int p, int val, int id = 1, int s = 0, int e = k) {
	if (e <= p || p < s) {
		return;
	}
	if (e - s == 1) {
		seg[sg][id] += val;
		seg[sg][id] %= mod;
		if (lazy[sg][id]) {
			seg[sg][id] = 0;
		}
		return;
	}
	shift(sg, id);
	int md = (s + e) / 2;
	add(sg, p, val, id * 2, s, md);
	add(sg, p, val, id * 2 + 1, md, e);
	seg[sg][id] = seg[sg][id * 2] + seg[sg][id * 2 + 1];
	seg[sg][id] %= mod;
	if (lazy[sg][id]) {
		seg[sg][id] = 0;
	}
}
void del(int sg, int l, int r, int id = 1, int s = 0, int e = k) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		lazy[sg][id] = true;
		seg[sg][id] = 0;
		return;
	}
	int md = (s + e) / 2;
	shift(sg, id);
	del(sg, l, r, id * 2, s, md);
	del(sg, l, r, id * 2 + 1, md, e);
	seg[sg][id] = seg[sg][id * 2] + seg[sg][id * 2 + 1];
	seg[sg][id] %= mod;
	if (lazy[sg][id]) {
		seg[sg][id] = 0;
	}	
}
int get(int sg, int l, int r, int id = 1, int s = 0, int e = k) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg[sg][id];
	}
	int md = (s + e) / 2;
	shift(sg, id);
	int ans = 0;
	ans += get(sg, l, r, id * 2, s, md);
	ans += get(sg, l, r, id * 2 + 1, md, e);
	ans %= mod;
	seg[sg][id] = seg[sg][id * 2] + seg[sg][id * 2 + 1];
	seg[sg][id] %= mod;
	if (lazy[sg][id]) {
		seg[sg][id] = 0;
	}	
	return ans;	
}
int32_t main() {
	cin >> k >> n >> m;
	vec.push_back(0);
	vec.push_back(k);
	for (int i = 1; i <= n + m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		vec.push_back(l[i]);
		vec.push_back(r[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
		r[i] = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin();
		q[r[i]].push_back({l[i], 0});
	}
	for (int i = n + 1; i <= n + m; i++) {
		l[i] = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
		r[i] = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin();
		q[r[i]].push_back({l[i], 1});
	}	
	k = vec.size();
//	cout << po(2, 5) << endl;
	add(0, 0, 1);
	add(1, 0, 1);
//	cout << "81 " << seg[0][1] << endl;
	for (int i = 1; i < k; i++) {
		long long t = 1ll * seg[0][1] * (po(2, vec[i] - vec[i - 1]) - 1 + mod);
		t %= mod;
	//	cout << "82 " << t << endl;
		add(0, i, t);
		add(1, i, t);
		for (auto p : q[i]) {
			int l = p.first, qt = p.second;
			if (qt) {
				int x = get(1, 0, l + 1);
			//	cout << "83 " << x << endl;
				del(1, 0, l + 1);
				add(0, i, mod - x);
			}
			else {
				int x = get(0, 0, l + 1);
			//	cout << "84 " << x << endl;
				del(0, 0, l + 1);
				add(1, i, mod - x);				
			}
		}
	}
	cout << seg[0][1];
	return 0;
}