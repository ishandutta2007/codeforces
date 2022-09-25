#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, SIZE = 500;

struct bucket_t {
	vector<size_t> sortedByB, stack;
	vector<long long> a, b;
	long long ans, addend;
	int size;
	size_t stackIt;
	
	bucket_t(int* a, int* b, int n, int sgn);
	
	void add(int l, int r, int x);
	long long get(int l, int r);
	
	void rebuild();
};

struct sqtr_t {
	vector<bucket_t> buckets;
	
	void init(int* a, int* b, int n, int sgn);
	void add(int l, int r, int x);
	long long get(int l, int r);
};

void sqtr_t::init(int* a, int* b, int n, int sgn) {
	for (int i = 0; i * SIZE < n; i++) {
		buckets.emplace_back(a, b, min(n - i * SIZE, SIZE), sgn);
		a += SIZE;
		b += SIZE;
	}
}

void sqtr_t::add(int l, int r, int x) {
	for (auto& b : buckets) {
		b.add(l, r, x);
		l -= SIZE;
		r -= SIZE;
	}
}

long long sqtr_t::get(int l, int r) {
	long long res = 0;
	for (auto& b : buckets) {
		res = max(res, b.get(l, r));
		l -= SIZE;
		r -= SIZE;
	}
	
	return res;
}

bucket_t::bucket_t(int* a, int* b, int n, int sgn) {
	addend = 0;
	size = n;
	for (int i = 0; i < n; i++) {
		this->a.push_back(a[i]);
		this->b.push_back(sgn * b[i]);
	}
	
	auto cmp = [&](size_t l, size_t r) {
		return this->b[l] < this->b[r];
	};
	
	sortedByB.resize(n);
	iota(sortedByB.begin(), sortedByB.end(), 0);
	sort(sortedByB.begin(), sortedByB.end(), cmp);
	
	rebuild();
}

void bucket_t::rebuild() {
	for (auto& x : a) x += addend;
	addend = 0;
	
	stack.clear();
	vector<long long> L;
	
	for (size_t i : sortedByB) {
yolo:
		if (stack.empty()) {
			stack.push_back(i);
			L.push_back(0);
			continue;
		}
		
		long long a1 = a[i];
		long long b1 = b[i];
		
		long long a2 = a[stack.back()];
		long long b2 = b[stack.back()];
		
		if (b1 == b2) {
			if (a1 * b1 <= a2 * b2) continue;
			stack.pop_back();
			L.pop_back();
			goto yolo;
		}
		
		long long p = a2 * b2 - a1 * b1;
		long long q = b1 - b2;
		
		long long x = max((p + q - 1) / q, 0ll);
		if (x <= L.back()) {
			stack.pop_back();
			L.pop_back();
			goto yolo;
		}
		
		stack.push_back(i);
		L.push_back(x);
	}
	
	stackIt = 0;
	
	ans = a[stack[stackIt]] * b[stack[stackIt]];
}

void bucket_t::add(int l, int r, int x) {
	l = max(l, 0);
	r = min(r, size - 1);
	
	if (l > r) return;
	
	if (l == 0 && r == size - 1) {
		addend += x;
		
		while (stackIt + 1 < stack.size() && (a[stack[stackIt]] + addend) * b[stack[stackIt]] <= (a[stack[stackIt + 1]] + addend) * b[stack[stackIt + 1]]) stackIt++;
		ans = (a[stack[stackIt]] + addend) * b[stack[stackIt]];
		
		return;
	}
	
	for (int i = l; i <= r; i++) {
		a[i] += x;
	}
	
	rebuild();
}

long long bucket_t::get(int l, int r) {
	l = max(l, 0);
	r = min(r, size - 1);
	
	if (l == 0 && r == size - 1) return ans;
	
	long long res = 0;
	for (int i = l; i <= r; i++) {
		res = max(b[i] * (a[i] + addend), res);
	}
	
	return res;
}

vector<int> G[MX];
int l[MX], r[MX], A[MX], B[MX], a[MX], b[MX];

void dfs(int v) {
	static int id = 0;
	
	a[id] = A[v];
	b[id] = B[v];
	
	l[v] = id++;
	
	for (int u : G[v]) {
		A[u] += A[v];
		B[u] += B[v];
		
		dfs(u);
	}
	
	r[v] = id - 1;
}

sqtr_t pos, neg;

int main() {
	int n, q;
	ignore = scanf("%d %d", &n, &q);
	for (int i = 1, p; i < n; i++) {
		ignore = scanf("%d", &p);
		G[p - 1].push_back(i);
	}
	
	for (int i = 0; i < n; i++) ignore = scanf("%d", A + i);
	for (int i = 0; i < n; i++) ignore = scanf("%d", B + i);
	
	dfs(0);
	
	pos.init(a, b, n, +1);
	neg.init(a, b, n, -1);
	
	while (q--) {
		int t, v;
		ignore = scanf("%d %d", &t, &v);
		v--;
		if (t == 1) {
			int x;
			ignore = scanf("%d", &x);
			
			pos.add(l[v], r[v], x);
			neg.add(l[v], r[v], x);
		}
		else {
			auto ans = max(pos.get(l[v], r[v]), neg.get(l[v], r[v]));
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}