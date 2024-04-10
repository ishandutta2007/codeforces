#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 2e5 + 5;

struct edge {
	int u, v;
	ll w;
	void input() {
		scanf("%d%d%lld", &u, &v, &w);
	}
	bool operator <(const edge &rhs) const {
		return w < rhs.w;
	}
};

int N, M;
ll a[MAXN];
edge e[MAXN];
int dad[MAXN], rnk[MAXN];
set <pii> all;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%lld", a + i);
	for (int i = 0; i < M; i++)
		e[i].input();
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

bool eq(int x, int y) {
	return find(x) == find(y);
}

void in(int x) {
	all.insert({a[x], x});
}

void out(int x) {
	all.erase({a[x], x});
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	assert(x != y);
	if (rnk[x] > rnk[y])
		swap(x, y);
	out(x);
	out(y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	a[y] = min(a[y], a[x]);
	in(y);
}

ll solve() {
	sort(e, e + M);
	
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		in(i);
	}
		
	ll sol = 0;
	int ptr = 0;
	for (int i = 1; i < N; i++) {
		while (ptr < M && eq(e[ptr].u, e[ptr].v))
			ptr++;
		auto it1 = all.begin();
		auto it2 = it1;
		it2++; 
		ll curr = it1 -> first + it2 -> first;
		int x = it1 -> second, y = it2 -> second;
		if (ptr < M && e[ptr].w < curr) {
			curr = e[ptr].w;
			x = e[ptr].u;
			y = e[ptr].v;
		}
		sol += curr;
		join(x, y);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}