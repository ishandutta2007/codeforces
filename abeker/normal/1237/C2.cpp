#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int N;
map <pii, set <pii>> two;
map <int, set <pii>> one;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		two[{x, y}].insert({z, i + 1});
	}
}

void output(int a, int b) {
	printf("%d %d\n", a, b);
}

void pairing(set <pii> &pts) {
	while (pts.size() > 1) {
		int a = pts.begin() -> second;
		pts.erase(pts.begin());
		int b = pts.begin() -> second;
		pts.erase(pts.begin());
		output(a, b);
	}
}

void solve() {
	for (auto it : two) {
		set <pii> tmp = it.second;
		pairing(tmp);
		if (!tmp.empty())
			one[it.first.first].insert({it.first.second, tmp.begin() -> second});
	}
	
	vector <int> rest;
	for (auto it : one) {
		set <pii> tmp = it.second;
		pairing(tmp);
		if (!tmp.empty())
			rest.push_back(tmp.begin() -> second);
	}
	
	for (int i = 0; i < rest.size(); i += 2)
		output(rest[i], rest[i + 1]);
}

int main() {
	load();
	solve();
	return 0;
}