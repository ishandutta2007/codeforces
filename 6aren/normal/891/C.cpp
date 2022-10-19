#include<bits/stdc++.h>
using namespace std;

const int N = 500005;

int p[N], en[N], n, m;
bool res[N];
stack<pair<int*, int>> cache;

struct Edge {
	int u, v, w;
} e[N];

struct Query {
	int id;
	vector<Edge> v;
} que[N];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

bool cmp2(const Query &x, const Query &y) {
	return x.v[0].w < y.v[0].w;
}

void change(int &x, int y) {
	cache.push(make_pair(&x, x));
	x = y;
}

void roolback() {
	while (!cache.empty()) {
		auto u = cache.top();
		(*u.first) = u.second;
		cache.pop();
	}
}

int find(int x) {
	if (p[x] == x) return x;
	int u = find(p[x]);
	change(p[x], u);
	return p[x];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	change(p[y], x);
}

int find1(int x) {
	if (p[x] == x) return x;
	int u = find1(p[x]);
	p[x] = u;
	return p[x];
}

void merge1(int x, int y) {
	x = find1(x);
	y = find1(y);
	if (x == y) return;
	p[y] = x;
}

bool calc(vector<Edge> &v) {
	bool res = true;
	for (auto u : v) {
		//cout << find(u.u) << ' ' << find(u.v) << endl;
		if (find(u.u) == find(u.v)) res = false;
		else merge(u.u, u.v);
		//cout << res << endl;
	}
	roolback();
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("a.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int id = 0;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		en[i - 1] = id;
		int k;
		cin >> k;
		vector<Edge> v;
		for (int i = 1; i <= k; i++) {
			int u; cin >> u;
			v.push_back(e[u]);
		}
		sort(v.begin(), v.end(), cmp);
		id++;
		que[id].v.push_back(v[0]);
		que[id].id = id;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].w != v[i - 1].w) {
				id++;
				que[id].v.push_back(v[i]);
				que[id].id = id;
			} else {
				que[id].v.push_back(v[i]);
			}
		}
	}
	en[q] = id;
	sort(que + 1, que + id + 1, cmp2);
	sort(e + 1, e + m + 1, cmp);
	int cur = 1;
	for (int i = 1; i <= id; i++) {
		while (e[cur].w < que[i].v[0].w) {
			merge1(e[cur].u, e[cur].v);
			cur++;
		}
		bool u = calc(que[i].v);
		res[que[i].id] = u;
	}
	for (int i = 1; i <= q; i++) {
		int ans = 1;
		for (int j = en[i - 1] + 1; j <= en[i]; j++) {
			ans = ans & res[j];
 		}
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}