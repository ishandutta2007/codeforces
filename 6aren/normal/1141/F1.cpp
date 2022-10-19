#include<bits/stdc++.h>

using namespace std;

struct Node {
	int l, r, val;
	Node(int l, int r, int val) : l(l), r(r), val(val) {};
};

int pref[1505], n;
vector<Node> v;
vector<pair<int, int>> res, temp;

bool cmp(Node x, Node y) {
	if (x.val == y.val) return x.l < y.l;
	return x.val < y.val;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		pref[i] = pref[i - 1] + u;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			v.push_back(Node(i, j, pref[j] - pref[i - 1]));
		}
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 1, ans = 0, r = v[0].r;
	temp.push_back(make_pair(v[0].l, v[0].r));
	for (int i = 1; i < v.size(); i++) {
		if (v[i].val != v[i - 1].val) {
			if (cnt > ans) {
				ans = cnt;
				res.clear();
				for (auto u : temp) {
					res.push_back(u);
				}
			}
			temp.clear();
			temp.push_back(make_pair(v[i].l, v[i].r));
			cnt = 1;
			r = v[i].r;
			continue;
		}
		if (v[i].l > r) {
			cnt++;
			temp.push_back(make_pair(v[i].l, v[i].r));
			r = v[i].r;
		} else {
			if (v[i].r < r) {
				r = v[i].r;
				temp[cnt - 1] = make_pair(v[i].l, v[i].r);
			}
		}
	}
	if (cnt > ans) {
		ans = cnt;
		res.clear();
		for (auto u : temp) {
			res.push_back(u);
		}
	}
	cout << ans << endl;
	for (auto u : res) {
		cout << u.first << ' ' << u.second << endl;
	}
	return 0;
}