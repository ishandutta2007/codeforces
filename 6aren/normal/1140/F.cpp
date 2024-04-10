#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back

const int N = 300005;
const int BASE = 300005;

vector<pair<int,int>> it[4 * N];

map<pair<int, int>, int> mp;

int q, val[80 * N], s1[2 * N], s2[2 * N], p[2 * N], cur = 0;

int *id[80 * N];
//

long long ans = 0, res[N];

void change(int &x, int y) {
	id[cur] = &x;
	val[cur] = x;
	x = y;
	cur++;
	return;
}

void rollback() {
	cur--;
	(*id[cur]) = val[cur];
	return;
}

int findDsu(int x) {
	if (p[x] == x) {
		return x;
	}
	return findDsu(p[x]);
}

void merge(int x, int y) {
	x = findDsu(x);
	y = findDsu(y);
	if (x == y) return;
	ans -= 1LL * s1[x] * s2[x] + 1LL * s1[y] * s2[y];
	if (s1[x] + s2[x] < s1[y] + s2[y]) {
		swap(x, y);
	} 
	change(p[y], x);
	change(s1[x], s1[x] + s1[y]);
	change(s2[x], s2[x] + s2[y]);
	ans += 1LL * s1[x] * s2[x];
	return;
}

void update(int k, int l, int r, int u, int v, pair<int, int> val) {
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		it[k].pb(val);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * k, l, mid, u, v, val);
	update(2 * k + 1, mid + 1, r, u, v, val);
	return;
}

void dfs(int k, int l, int r) {
	long long last_ans = ans;
	int state = cur;
	for (auto x : it[k]) {
		merge(x.first, x.second + BASE);
	}
	if (l == r) {
		res[l] = ans;
	} else {
		int mid = (l + r) / 2;
		dfs(2 * k, l, mid);
		dfs(2 * k + 1, mid + 1, r);
	}
	while (cur != state) rollback();
	ans = last_ans;
	return;
}

void init() {
	for (int i = 1; i < 2 * N; i++) {
		p[i] = i;
	}
	for (int i = 1; i < N; i++) {
		s1[i] = 1;
		s2[i + BASE] = 1;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> q;
	init();
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		pair<int, int> ii = make_pair(x, y);
		if (mp.count(ii)) {
			update(1, 1, q, mp[ii], i - 1, ii);
			mp.erase(ii);
		} else {
			mp[ii] = i;
		}
	}
	for (auto u : mp) {
		update(1, 1, q, u.y, q, u.x);
	}
	dfs(1, 1, q);
	for (int i = 1; i <= q; i++) {
		cout << res[i] << ' ';
	}
	return 0;
}