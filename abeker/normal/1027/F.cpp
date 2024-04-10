#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;

int N;
int a[MAXN], b[MAXN];
vector <int> E[MAXN];
vector <int> v;
bool bio[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
}

void compress(int &ref) {
	ref = lower_bound(v.begin(), v.end(), ref) - v.begin();
}

void dfs(int x, int &m1, int &m2, int &d) {
	bio[x] = true;
	if (v[x] >= m1) {
		m2 = m1;
		m1 = v[x];
	}
	else if (v[x] > m2)
		m2 = v[x];
	d += (int)E[x].size() - 2;
	for (auto it : E[x])
		if (!bio[it])
			dfs(it, m1, m2, d);
}

int solve() {
	for (int i = 0; i < N; i++) {
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	for (int i = 0; i < N; i++) {
		compress(a[i]);
		compress(b[i]);
		E[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
	
	int sol = 0;
	for (int i = 0; i < v.size(); i++)
		if (!bio[i]) {
			int mx1 = 0, mx2 = 0, diff = 0;
			dfs(i, mx1, mx2, diff);
			if (diff > 0)
				return -1;
			sol = max(sol, diff < 0 ? mx2 : mx1);
		}
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}