#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

struct frog_t {
	int x;
	long long r;
	
	frog_t(int _x, long long _r) : x(_x), r(_r) {}
	
	bool operator < (const frog_t &RHS) const {
		if (r != RHS.r) return r < RHS.r;
		
		return x > RHS.x;
	}
};

multiset<frog_t> frogs, bees;
map<int, int> id;
long long x[MX], t[MX], ans[MX];

void addFrog(int x, long long r) {
	frog_t b(1000000001, x);
	while (true) {
		auto iter = bees.lower_bound(b);
		
		if (iter == bees.end() || iter->r > r) break;
		
		r += iter->x;
		t[id[x]] += iter->x;
		ans[id[x]] += 1;
		
		bees.erase(iter);
	}
	
	frog_t f(x, r);
	while (true) {
		auto iter = frogs.lower_bound(f);
		
		if (iter != frogs.end() && iter->x < x) return;
		if (iter == frogs.begin()) break;
		
		iter--;
		
		if (iter->x > x) frogs.erase(iter);
		else break;
	}
	
	frogs.insert(f);
}

void addBee(int x, int y) {
	frog_t b(1000000001, x);
	int X = -1;
	long long R;
	auto iter = frogs.lower_bound(b);
	if (iter != frogs.end() && iter->x <= x) {
		X = iter->x;
		R = iter->r;
		
		frogs.erase(iter);
	}
	
	bees.emplace(y, x);
	
	if (X != -1) addFrog(X, R);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", x + i, t + i);
		
		addFrog(x[i], x[i] + t[i]);
		
		id[x[i]] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int p, b;
		scanf("%d %d", &p, &b);
		
		addBee(p, b);
	}
	
	for (int i = 0; i < n; i++) printf("%lld %lld\n", ans[i], t[i]);
	
	return 0;
}