#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;

struct triple {
	ld l, r;
	int id;
	bool operator <(const triple &rhs) const {
		if (l != rhs.l)
			return l < rhs.l;
		return r > rhs.r;
	}
};

int N, M;
ld P, Q;
pair <ld, ld> L[MAXN];
vector <ld> all;
vector <triple> v;

ld dist(ld a1, ld b1, ld a2, ld b2) {
	ld x = (b2 - b1) / (a1 - a2);
	ld y = a1 * x + b1;
	return sqrt(x * x + y * y);
}

struct tournament {
	int cnt[2 * offset];
	vector <int> pts[2 * offset];
	
	void init() {
		for (int i = 0; i < 2 * offset; i++) {
			pts[i].clear();
			cnt[i] = 0;
		}
	}
	
	void update(int x, int who) {
		if (who == -1) {
			for (x += offset; x; x /= 2) 
				cnt[x]++;
			return;
		}
		for (x += offset; x; x /= 2) 
			pts[x].push_back(who);
	}
	
	ld query(int x, int lo, int hi, int from, int to, int who) {
		if (lo >= to || hi <= from)
			return 0;
		if (lo >= from && hi <= to) {
			if (who == -1)
				return cnt[x];
			ld res = 0;
			for (auto it : pts[x])
				res += dist(L[it].first, L[it].second, L[who].first, L[who].second);
			return res;
		}
		int mid = (lo + hi) / 2;
		return query(2 * x, lo, mid, from, to, who) + query(2 * x + 1, mid, hi, from, to, who);
	}
};

tournament T;

void scale(ld &x, ld &y) {
	x /= 1000;
	y /= 1000;
}

void load() {
	scanf("%d%Lf%Lf%d", &N, &P, &Q, &M);
	scale(P, Q);
	for (int i = 0; i < N; i++) {
		ld a, b;
		scanf("%Lf%Lf", &a, &b);
		scale(a, b);
		L[i] = {a, a * P + b - Q};
	}
}

void intersect(ld a, ld b, ld r, int who) {
	ld A = a * a + 1;
	ld B = 2 * a * b;
	ld C = b * b - r * r;
	ld D = B * B - 4 * A * C;
	if (D < 0)
		return;
	ld x1 = (-B + sqrt(D)) / (2 * A);
	ld x2 = (-B - sqrt(D)) / (2 * A);
	ld alpha1 = atan2(a * x1 + b, x1);
	ld alpha2 = atan2(a * x2 + b, x2);
	if (alpha1 > alpha2)
		swap(alpha1, alpha2);
	v.push_back({alpha1, alpha2, who});
	all.push_back(alpha1);
	all.push_back(alpha2);
}

void compress(ld &ref) {
	ref = lower_bound(all.begin(), all.end(), ref) - all.begin();
}

ld calc(ld r, bool sum = false) {
	T.init();
	all.clear();
	v.clear();
	for (int i = 0; i < N; i++)
		intersect(L[i].first, L[i].second, r, i);

	sort(all.begin(), all.end());
	
	for (auto &it : v) {
		compress(it.l);
		compress(it.r);
	}
	
	sort(v.begin(), v.end());
	
	ld res = 0;
	for (auto it : v) {
		res += T.query(1, 0, offset, it.l, it.r + 1, sum ? it.id : -1);
		T.update(it.r, sum ? it.id : -1);
	}
	
	return res;
}

ld solve() {
	ld lo1 = 0, hi1 = 4e9;
	ld lo2 = 0, hi2 = 4e9;
	for (int it = 0; it < 60; it++) {
		ld mid1 = (lo1 + hi1) / 2;
		ld mid2 = (lo2 + hi2) / 2;
		if (calc(mid1) < M)
			lo1 = mid1;
		else
			hi1 = mid1;
		if (calc(mid2) >= M)
			hi2 = mid2;
		else
			lo2 = mid2;
	}
	
	return calc(lo1, true) + (M - calc(lo1)) * lo2;
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}