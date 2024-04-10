#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;

int N;
int idx[MAXN];
bool adj[MAXN][MAXN];
vector <pii> st, en;
vector <pii> ans;

void input(vector <pii> &v) {
	for (int i = 0; i < N - 3; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({--a, --b});
	}
}

void load() {
	scanf("%d", &N);
	input(st);
	input(en);
}

inline bool in_range(int val, pii range) {
	return val > range.first && val < range.second;
}

inline int calc_dist(int v, pii range, int n) {
	if (in_range(v, range))
		return v - range.first;
	range.first -= v;
	if (range.first < 0)
		return range.first + n;
	return range.first;
}

void modify(pii p, pii q, map <pii, pii> &m) {
	if (m.find(p) == m.end())
		swap(p.first, p.second);
	pii &ref = m[p];
	if (ref.first == q.second)
		ref.first = q.first;
	else
		ref.second = q.first;
}

void dac(const vector <int> &vert, map <pii, pii> diag, const vector <pii> &target) {
	int n = vert.size();
	if (n == 3)
		return;
	for (int i = 0; i < n; i++)
		idx[vert[i]] = i;
	pii opt = {-1, -1};
	for (auto it : target) {
		int dist = abs(idx[it.first] - idx[it.second]);
		if (dist >= n / 3 && dist <= (2 * n + 1) / 3) {
			opt = {idx[it.first], idx[it.second]};
			break;
		}
	}
	assert(opt != pii(-1, -1));
	if (opt.first > opt.second)
		swap(opt.first, opt.second);
	vector <pair <int, pii>> toflip;
	for (auto it : diag) {
		pii tmp = {idx[it.first.first], idx[it.first.second]};
		if (tmp.first == opt.first || tmp.first == opt.second)
			continue;
		if (tmp.second == opt.first || tmp.second == opt.second)
			continue;
		if (in_range(tmp.first, opt) ^ in_range(tmp.second, opt))
			toflip.push_back({calc_dist(tmp.first, opt, n) + calc_dist(tmp.second, opt, n), it.first});
	}
	sort(toflip.begin(), toflip.end());
	for (auto it : toflip) {
		pii curr = it.second;
		pii other = diag[curr];
		diag.erase(diag.find(curr));
		diag[other] = curr;
		ans.push_back(curr);
		modify({other.first, curr.first}, {other.second, curr.second}, diag);
		modify({other.second, curr.first}, {other.first, curr.second}, diag);
		modify({other.first, curr.second}, {other.second, curr.first}, diag);
		modify({other.second, curr.second}, {other.first, curr.first}, diag); 
	}
	vector <int> lft, rig;
	for (int i = opt.first; i <= opt.second; i++)
		rig.push_back(vert[i]);
	for (int i = opt.second; ; i = (i + 1) % n) {
		lft.push_back(vert[i]);
		if (i == opt.first)
			break;
	}
	map <pii, pii> diag_lft, diag_rig;
	vector <pii> target_lft, target_rig;
	pii incl = {opt.first - 1, opt.second + 1};
	for (auto it : diag) {
		pii tmp = {idx[it.first.first], idx[it.first.second]};
		if (tmp.first > tmp.second)
			swap(tmp.first, tmp.second);
		if (tmp == opt)
			continue;
		if (in_range(tmp.first, incl) && in_range(tmp.second, incl))
			diag_rig[it.first] = it.second;
		else
			diag_lft[it.first] = it.second;
	}
	for (auto it : target) {
		pii tmp = {idx[it.first], idx[it.second]};
		if (tmp.first > tmp.second)
			swap(tmp.first, tmp.second);
		if (tmp == opt)
			continue;
		if (in_range(tmp.first, incl) && in_range(tmp.second, incl))
			target_rig.push_back(it);
		else
			target_lft.push_back(it);
	}
	dac(lft, diag_lft, target_lft);
	dac(rig, diag_rig, target_rig);
}

void solve() {
	vector <int> all;
	for (int i = 0; i < N; i++) {
		adj[i][(i + 1) % N] = adj[(i + 1) % N][i] = true;
		all.push_back(i);
	}
	for (auto it : st)
		adj[it.first][it.second] = adj[it.second][it.first] = true;
		
	map <pii, pii> d;
	for (auto it : st) {
		vector <int> tmp;
		for (int i = 0; i < N; i++)
			if (adj[it.first][i] && adj[it.second][i])
				tmp.push_back(i);
		assert(tmp.size() == 2);
		d[it] = {tmp[0], tmp[1]};
	}
	
	dac(all, d, en);	
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d\n", it.first + 1, it.second + 1);
}

int main() {
	load();
	solve();
	return 0;
}