#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef pair <ld, ld> point;

const ld eps = 1e-6;

int N;
vector <pii> lines;
vector <pii> envelope;
vector <point> pts;

void load() {
	scanf("%d", &N);
	while (N--) {
		int x, y;
		scanf("%d%d", &x, &y);
		lines.push_back({x, y - (ll)x * x});
	}
}

ld eval(pii p, ld x) {
	return p.first * x + p.second;
}

point intersect(pii p, pii q) {
	ld x = (ld)(q.second - p.second) / (p.first - q.first);
	return {x, eval(p, x)};
}

int solve() {
	sort(lines.begin(), lines.end());
	
	for (auto it : lines) {
		while (envelope.size() > 1 && !pts.empty() && eval(it, pts.back().first) + eps > pts.back().second) {
			envelope.pop_back();
			pts.pop_back();
		}
		if (!envelope.empty()) { 
			if (envelope.back().first == it.first)
				envelope.pop_back();
			else
				pts.push_back(intersect(envelope.back(), it));	
		}
		envelope.push_back(it);
	}
		
	return pts.size();
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}