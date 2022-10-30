#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, cl, ce, v;
	cin >> N >> M >> cl >> ce >> v;
	set<int> s;
	set<int> e;
	int res = 0;
	int a;
	for (int i = 0; i < cl; i++) {
		cin >> a;
		a--;
		s.insert(a);
	}
	for (int i = 0; i < ce; i++) {
		cin >> a;
		a--;
		e.insert(a);
	}
	int q;
	cin >> q;
	vector<int> x1(q);
	vector<int> y1(q);
	vector<int> x2(q);
	vector<int> y2(q);
	for (int i = 0; i < q; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		swap(x1[i], y1[i]);
		swap(x2[i], y2[i]);
	}
	for (int i = 0; i < q; i++) {
		if (y1[i] == y2[i]) {
			cout << abs(x1[i] - x2[i]) << endl;
			continue;
		}
		x1[i]--;
		x2[i]--;
		int res = (int)1 << 60;
		int t;
		int u = abs(y1[i] - y2[i]);
		if (s.count(x1[i]) == 1) {
			t = u + abs(x1[i] - x2[i]);
			res = min(res, t);
		}
		else {
			s.insert(x1[i]);
			auto x = s.find(x1[i]);
			x++;
			if (x != s.end()) {
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
			}
			x--;
			if (x != s.begin()) {
				x--;
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
				x++;
			}
			s.erase(x1[i]);
		}
		if (s.count(x2[i]) == 1) {
			t = u + abs(x1[i] - x2[i]);
			res = min(res, t);
		}
		else {
			s.insert(x2[i]);
			auto x = s.find(x2[i]);
			x++;
			if (x != s.end()) {
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
			}
			x--;
			if (x != s.begin()) {
				x--;
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
				x++;
			}
			s.erase(x2[i]);
		}
		u = 1 + ((abs(y1[i] - y2[i]) - 1) / v);
		if (e.count(x1[i]) == 1) {
			t = u + abs(x1[i] - x2[i]);
			res = min(res, t);
		}
		else {
			e.insert(x1[i]);
			auto x = e.find(x1[i]);
			x++;
			if (x != e.end()) {
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
			}
			x--;
			if (x != e.begin()) {
				x--;
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
				x++;
			}
			e.erase(x1[i]);
		}
		if (e.count(x2[i]) == 1) {
			t = u + abs(x1[i] - x2[i]);
			res = min(res, t);
		}
		else {
			e.insert(x2[i]);
			auto x = e.find(x2[i]);
			x++;
			if (x != e.end()) {
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
			}
			x--;
			if (x != e.begin()) {
				x--;
				t = u + abs((*x) - x1[i]) + abs((*x) - x2[i]);
				res = min(res, t);
				x++;
			}
			e.erase(x2[i]);
		}
		cout << res << endl;
	}
}