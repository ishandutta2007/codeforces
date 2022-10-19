#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

struct event {
	int val, lo, hi, type, idx;
	bool operator <(const event &rhs) const {
		if (val != rhs.val)
			return val < rhs.val;
		return type > rhs.type;
	}
};

int N;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
}

bool dfs(const vector <int> &v, int dir) {
	if (v.size() <= 1)
		return true;
	vector <event> sweep;
	if (dir) 
		for (auto it : v) {
			sweep.push_back({b[it], a[it], c[it], 0, it});
			sweep.push_back({d[it], a[it], c[it], 1, it});
		}
	else 
		for (auto it : v) {
			sweep.push_back({a[it], b[it], d[it], 0, it});
			sweep.push_back({c[it], b[it], d[it], 1, it});
		}
	sort(sweep.begin(), sweep.end());
	vector <int> done;
	int open = 0;
	for (auto it : sweep) {
		if (it.type) {
			open--;
			done.push_back(it.idx);
		}
		else
			open++;
		if (!open) {
			if (done.size() == v.size() || !dfs(done, dir ^ 1))
				return false;
			done.clear();
		}
	}
	return true;
}

bool solve() {
	vector <int> all;
	for (int i = 0; i < N; i++)
		all.push_back(i);
	return dfs(all, 0) || dfs(all, 1);
}

int main() {
	load();
	puts(solve() ? "YES" : "NO");
	return 0;
}