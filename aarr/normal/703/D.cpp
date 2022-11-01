#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


const int N = 1000 * 1000 + 5, LG = 21;
int n, q;

//vector <pair <int, int> > vec[N * 4];
vector <pair <int, int> > t[N];
pair <int, int> d[LG][N];
int it[N * 4];
int seg[N * 4];
int a[N];
int ans[N];
int prv[N];
map <int, int> lt;

void build(int id = 1, int s = 0, int e = n, int lv = 0) {
	if (e - s == 1) {
	//	vec[id].push_back({prv[s], a[s]});
		seg[id] = a[s];
		d[lv][s] = {prv[s], a[s]};
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md, lv + 1);
	build(id * 2 + 1, md, e, lv + 1);
//	vec[id].resize(e - s);
//	cout << 71 << endl;
	merge(d[lv + 1] + s, d[lv + 1] + md, d[lv + 1] + md, d[lv + 1] + e, d[lv] + s);
//	cout << 72 << endl;
	seg[id] = seg[id * 2] ^ seg[id * 2 + 1];
}

int get(int l, int r, int id = 1, int s = 0, int e = n, int lv = 0) {
	if (l <= s && e <= r) {
	//	cout << "78 " << id << " " << seg[id] << " " << it[id] << endl;
		while (it[id] < e - s && d[lv][it[id] + s].first < l) {
			seg[id] ^= d[lv][it[id] + s].second;
			it[id]++;
		}
		return seg[id];
	}	
	if (e <= l || r <= s) {
		return 0;
	}
	int md = (s + e) / 2;
	int ans = get(l, r, id * 2, s, md, lv + 1);
	ans ^= get(l, r, id * 2 + 1, md, e, lv + 1);
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prv[i] = lt[a[i]] - 1;
		lt[a[i]] = i + 1;
	}
	lt.clear();
	build();
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		t[l].push_back({r, i});
	}
//	cout << "75\n";
	for (int i = 0; i < n; i++) {
		for (auto p : t[i]) {
			ans[p.second] = get(i, p.first);
//			cout << "73 " << i << " " << p.first << " " << p.second << " " << ans[p.second] << endl;
		}
	}
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << "71 " << i << " " << j << " " << d[i][j].second << endl;
//		}
//	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}