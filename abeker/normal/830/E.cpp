#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
vector <int> E[MAXN];
bool bio[MAXN];
int sol[MAXN];
vector <int> path, comp;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		E[i].clear();
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

void output() {
	puts("YES");
	for (int i = 1; i <= N; i++)
		printf("%d ", sol[i]);
	puts("");
}

bool dfs(int x, int p) {
	bio[x] = true;
	path.push_back(x);
	for (auto it : E[x])
		if (it != p) {
			if (bio[it]) {
				for (; ; path.pop_back()) {
					sol[path.back()] = 1;
					if (path.back() == it)
						break;
				}
				return true;
			}
			if (dfs(it, x))
				return true;
		}
	path.pop_back();
	return false;
}

void go(int x, int p) {
	bio[x] = true;
	comp.push_back(x);
	for (auto it : E[x])
		if (it != p)
			go(it, x);
}

bool find(int x, int p, int y) {
	path.push_back(x);
	if (x == y) {
		for (auto it : path)
			sol[it] = 2;
		return true;
	}
	for (auto it : E[x])
		if (it != p && find(it, x, y))
			return true;
	path.pop_back();
	return false;
}

void fill(int x) {
	for (auto it : E[x])
		if (!sol[it])
			sol[it] = 1;
}

void finish(int x, int y) {
	path.clear();
	find(x, 0, y);
	fill(x);
	fill(y);
}

bool cmp(const vector <int> &lhs, const vector <int> &rhs) {
	return lhs.size() < rhs.size();
}

bool work(int x) {
	vector <int> v[3];
	for (int i = 0; i < 3; i++) {
		int curr = E[x][i];
		int prev = x;
		while (1) {
			v[i].push_back(curr);
			if (E[curr].size() == 1)
				break;
			int tmp = curr;
			curr = E[curr][0] + E[curr][1] - prev;
			prev = tmp;
		}
	}
	
	sort(v, v + 3, cmp);
	
	if (v[0].size() > 1) {
		sol[x] = 3;
		for (int i = 0; i < 3; i++)
			for (auto it : v[i])
				sol[it] = it == v[i].back() ? 1 : 2;
		return true;
	}
	
	if (((int)v[1].size() - 1) * ((int)v[2].size() - 1) < 4)
		return false;
	
	if (v[1].size() == 2) {
		sol[x] = 6;
		sol[v[0][0]] = 3;
		sol[v[1][0]] = 4;
		sol[v[1][1]] = 2;
		for (int i = 0; i < v[2].size(); i++)
			sol[v[2][i]] = i + 1 == v[2].size() ? 1 : max(5 - i, 2);
		return true;
	}
	
	sol[x] = 4;
	sol[v[0][0]] = 2;
	for (int i = 1; i < 3; i++)
		for (int j = 0; j < v[i].size(); j++)
			sol[v[i][j]] = j + 1 == v[i].size() ? 1 : max(3 - j, 2);
	return true;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		sol[i] = 0;
		bio[i] = false;
	}
	
	for (int i = 1; i <= N; i++)
		if (E[i].size() >= 4) {
			fill(i);
			sol[i] = E[i].size() / 2;
			output();
			return;
		}

	path.clear();		
	for (int i = 1; i <= N; i++)
		if (!bio[i] && dfs(i, 0)) {
			output();
			return;
		}
	
	for (int i = 1; i <= N; i++)
		bio[i] = false;
	
	for (int i = 1; i <= N; i++)
		if (!bio[i]) {
			comp.clear();
			go(i, 0);
			vector <int> three;
			for (auto it : comp)
				if (E[it].size() == 3)
					three.push_back(it);
			if (three.empty())
				continue;
			if (three.size() > 1) {
				finish(three[0], three[1]);
				output();
				return;
			}
			if (work(three[0])) {
				output();
				return;
			}
		}
		
	puts("NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		load();
		solve();
	}
	return 0;
}