#include <bits/stdc++.h>

using namespace std;

struct pt {
    long long x, y;
    
    pt(int x, int y) : x(x), y(y) { }
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

long long cp(pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}

long long dist(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cw(pt a, pt b, pt c) {
    return cp(a, b, c) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return cp(a, b, c) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

vector<pair<long long, long long>> foo(int n) {
	vector<pt> pts;
	while (n--) {
		int x, y;
		ignore = scanf("%d %d", &x, &y);
		pts.emplace_back(x, y);
	}
	
	convex_hull(pts);
	
	pts.push_back(pts[0]);
	pts.push_back(pts[1]);
	
	vector<pair<long long, long long>> res;
	for (size_t i = 0; i + 2 < pts.size(); i++) {
		res.emplace_back(
			cp(pts[i], pts[i + 1], pts[i + 2]),
			dist(pts[i], pts[i + 1])
		);
	}
	
	return res;
}

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	auto a = foo(n);
	auto b = foo(m);
	
	if (a.size() != b.size()) {
		printf("%s\n", "NO");
		return 0;
	}
	
	decltype(a) v;
	for (auto x : a) v.push_back(x);
	v.emplace_back(0, 0);
	for (auto x : b) v.push_back(x);
	for (auto x : b) v.push_back(x);
	
	vector<size_t> kmp(v.size(), 0);
	for (size_t i = 1; i < v.size(); i++) {
		size_t j = kmp[i - 1];
		while (j > 0 && v[i] != v[j]) j = kmp[j - 1];
		
		if (v[i] == v[j]) kmp[i] = j + 1;
		else kmp[i] = 0;
		
		if (kmp[i] == a.size()) {
			printf("%s\n", "YES");
			return 0;
		}
	}
	
	printf("%s\n", "NO");
	
	return 0;
}