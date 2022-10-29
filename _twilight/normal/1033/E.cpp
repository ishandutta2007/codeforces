#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef vector<int> vec;

const int N = 605;

int n;
vec _V;
boolean vis[N];
vector<int> Tr[N];

int query(vec S) {
	if (!S.size()) {
		return 0;
	}
	printf("? %d\n", (signed) S.size());
	for (auto x : S) {
		printf("%d ", x);
	}
	putchar('\n');
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
int query(vec S, int x) {
	int a = query(S);
	S.push_back(x);
	int b = query(S);
	return b - a;
}

void update_opposite() {
	_V.clear();
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			_V.push_back(i);
		}
	}
}

vec subseq(vec v, int l, int r) {
	vec rt;
	for (int i = l; i <= r; i++)
		rt.push_back(v[i]);
	return rt;
}

queue<int> Q;
void bfs() {
	Q.push(1);
	vis[1] = true;
	update_opposite();
	while (!_V.empty()) {
		int e = Q.front();
		int l = 0, r = (signed) _V.size() - 1;
		if (!query(_V, e)) {
			Q.pop();
			continue;
		}
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query(subseq(_V, l, mid), e)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		Q.push(_V[l]);
		vis[_V[l]] = true;
		Tr[e].push_back(_V[l]);
		Tr[_V[l]].push_back(e);
		update_opposite();
	}
}

vec vL, vR;
int d[N], fa[N];
void dfs(int p, int fa) {
	d[p] = d[fa] + 1, ::fa[p] = fa;
	((d[p] & 1) ? vL : vR).push_back(p);
	for (auto e : Tr[p]) {
		if (e ^ fa) {
			dfs(e, p);
		}
	}
}

int main() {
	scanf("%d", &n);
	bfs();
	dfs(1, 0);
	if (query(vL) == 0) {
		if (query(vR) == 0) {
			printf("Y %d\n", (signed) vL.size());
			for (auto x : vL) {
				printf("%d ", x);
			}
			putchar('\n');
			fflush(stdout);
			return 0;
		}
		swap(vL, vR);
	}
	for (int i = 0; i < (signed) vL.size(); i++) {
		int p = vL[i];
		vec S;
		for (auto x : vL) {
			if (x ^ p) {
				S.push_back(x);
			}
		}
		if (query(S, p)) {
			int l = 0, r = (signed) S.size() - 1, mid;
			while (l < r) {
				mid = (l + r) >> 1;
				if (query(subseq(S, l, mid), p)) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			vector<int> cir, cirR;
			int x = p, y = S[l];
			while (x ^ y) {
				if (d[x] < d[y]) {
					cirR.push_back(y);
					y = fa[y];
				} else {
					cir.push_back(x);
					x = fa[x];
				}
			}
			cir.push_back(x);
			reverse(cirR.begin(), cirR.end());
			for (auto e : cirR)
				cir.push_back(e);
			printf("N %d\n", (signed) cir.size());
			for (auto e : cir) {
				printf("%d ", e);
			}
			putchar('\n');
			fflush(stdout);
			return 0;
		}
	}
	assert(false);
	return 0;
}