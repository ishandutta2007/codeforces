#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;
const int INF = 0x3f3f3f3f;

int N;
pii p[MAXN];
int tour[2 * offset];
multiset <int> lens;
set <pii> blocks;
bool was[MAXN];
int ans[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
}

void update(int x, int lo, int hi, int from, int to, int val) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		tour[x] = min(tour[x], val);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
}

int query(int x) {
	int res = INF;
	for (x += offset; x; x /= 2)
		res = min(res, tour[x]);
	return res;
}

void kill(int l, int r, int val) {
	update(1, 0, offset, l, r + 1, val);
}

void in(pii range, int val) {
	blocks.insert(range);
	lens.insert(range.first - range.second + 1);
	if (!val)
		return;
	if (was[range.first])
		kill((range.first + range.second + 1) / 2, range.first, val);
	if (was[range.second]) 
		kill(range.second, (range.first + range.second) / 2, val);
}

void out(pii range) {
	blocks.erase(range);
	lens.erase(lens.find(range.first - range.second + 1));
}

void output() {
	for (auto it : blocks)	
		printf("[%d, %d] ", it.second, it.first);
	puts("");
}

void solve() {
	if (N == 1) {
		printf("0\n%d\n", p[0].first);
		return;
	}
	
	memset(tour, INF, sizeof tour);
	
	sort(p, p + N);
	for (int i = 0; i < N; i++) 
		in({i, i}, 0);
	
	int sol = 0;
	for (int i = 0; i < N; i++) {
		int pos = p[i].second;
		was[pos] = true;
		auto it = blocks.lower_bound({pos, 0});
		if (it -> first > pos && it -> second < pos) {
			pii tmp = *it;
			in({it -> first, pos + 1}, p[i].first);
			in({pos - 1, it -> second}, p[i].first);
			in({pos, pos}, p[i].first);
			out(tmp);
		}
		else if (it -> first > pos && it -> second >= pos) {
			pii tmp = *it;
			in({it -> first, pos + 1}, p[i].first);
			if (pos) {
				pii lft = *(--it); 
				in({pos, it -> second}, p[i].first);
				out(lft);
			}
			else
				in({pos, pos}, p[i].first);
			out(tmp);
		}
		else if (it -> first <= pos && it -> second < pos) {
			pii tmp = *it;
			in({pos - 1, it -> second}, p[i].first);
			if (pos < N - 1) {
				pii rig = *(++it);
				in({it -> first, pos}, p[i].first);
				out(rig);
			}
			else
				in({pos, pos}, p[i].first);
			out(tmp);
		}
		else {
			if (pos == 0) {
				pii tmp = *it;
				pii rig = *(++it);
				in({it -> first, pos}, p[i].first);
				out(rig);
				out(tmp);
			}
			else if (pos == N - 1) {
				pii tmp = *it;
				pii lft = *(--it);
				in({pos, it -> second}, p[i].first);
				out(lft);
				out(tmp);
			}
			else {
				int lo = (--it) -> second;
				pii lft = *it;
				it++;
				pii tmp = *it;
				int hi = (++it) -> first;
				pii rig = *it;
				in({hi, lo}, p[i].first);
				out(lft);
				out(rig);
				out(tmp);
			}
		}
		if (i == N - 1 || p[i].first < p[i + 1].first)
			sol = max(sol, (*lens.rbegin() - 1) / 2);
	}
	
	printf("%d\n", sol);
	for (int i = 0; i < N; i++)
		printf("%d ", query(i));
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}