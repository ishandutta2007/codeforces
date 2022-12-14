#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 100500;

int N, K;

struct point {
	lf x, y;
	point(lf x = 0, lf y = 0) : x(x), y(y) { }
};

struct line {
	lf a, b, c; int f;
	line(lf a = 0, lf b = 0, lf c = 0, int f = 0) : a(a), b(b), c(c), f(f) { }
	lf val(lf x, lf y) { return a * x + b * y + c; }
} D[N_];

vector<line> cands;
vector<int> ans;

unsigned long long llrand() { // from http://stackoverflow.com/questions/28115724/getting-big-random-numbers-in-c-c
	unsigned long long r = 0;

	for (int i = 0; i < 5; ++i) {
		r = (r << 15) | (rand() & 0x7FFF);
	}

	return r & 0xFFFFFFFFFFFFFFFFULL;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("568D.in", "r", stdin);
	freopen("568D.out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		lf a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		cands.push_back(line(a, b, c, i));
	}


	while (cands.size() > K) {
		int best = -1; line best_l1, best_l2; point best_p;
		for (int rep = 0; rep < 500; rep++) {
			line l1 = cands[llrand() % cands.size()];
			line l2 = cands[llrand() % cands.size()];
			if (l1.f == l2.f) continue;

			// intersection point from https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
			double det = l2.a*l1.b - l1.a*l2.b;
			if (fabs(det) < 1e-9) continue;
			point p = point((l2.b*l1.c - l1.b*l2.c) / det, (l1.a*l2.c - l2.a*l1.c) / det);

			int good = 0;
			for (auto l : cands) if (fabs(l.val(p.x, p.y)) < 2e-9) ++good;
			if (good > best) {
				best = good;
				best_l1 = l1, best_l2 = l2; best_p = p;
			}
			if (best * K >= cands.size()) break;
		}

		if (best * K < cands.size()) return 0 & puts("NO");

		vector<line> new_cands;
		for (auto l : cands) if (fabs(l.val(best_p.x, best_p.y)) > 2e-9) new_cands.push_back(l);
		ans.push_back(best_l1.f); ans.push_back(best_l2.f);
		cands = new_cands;
		--K;
	}

	for (auto l : cands) {
		ans.push_back(l.f);
		ans.push_back(-1);
	}

	printf("YES\n%u\n", ans.size() / 2);
	for (int i = 0; i < ans.size() / 2; i++) printf("%d %d\n", ans[i + i], ans[i + i + 1]);

	return 0;
}