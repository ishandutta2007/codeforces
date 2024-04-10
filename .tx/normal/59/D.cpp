#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct rec {
	int x, y, z;
	rec() {};
	rec(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, i, k;
	scanf("%d", &n);
	vector<int> a(3 * n), p(3 * n + 1);
	vector<rec> d(n);
	for (i = 0; i < 3 * n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &d[i].x, &d[i].y, &d[i].z);
	}
	scanf("%d", &k);
	set<int> used, want, notused = set<int>(a.begin(), a.end());
	rec t;
	int g;
	for (i = 0; i < n; i++) {
		t = d[i];
		notused.erase(t.x);
		notused.erase(t.y);
		notused.erase(t.z);
		if (t.x == k) {
			if (p[t.x] < p[t.y] && p[t.x] < p[t.z]) {
				want.insert(t.y);
				want.insert(t.z);
				break;
			}
			else {
				for (i = 1; i <= 3 * n; i++) {
					if (i != k) {
						printf("%d ", i);
					}
				}
				return 0;
			}
		}
		if (t.y == k) {
			if (p[t.y] < p[t.x] && p[t.y] < p[t.z]) {
				want.insert(t.x);
				want.insert(t.z);
				break;
			}
			else {
				for (i = 1; i <= 3 * n; i++) {
					if (i != k) {
						printf("%d ", i);
					}
				}
				return 0;
			}
		}
		if (t.z == k) {
			if (p[t.z] < p[t.y] && p[t.z] < p[t.x]) {
				want.insert(t.y);
				want.insert(t.x);
				break;
			}
			else {
				for (i = 1; i <= 3 * n; i++) {
					if (i != k) {
						printf("%d ", i);
					}
				}
				return 0;
			}
		}
		used.insert(t.x);
		used.insert(t.y);
		used.insert(t.z);
	}
	int x, y;
	while (/*!used.empty() ||*/ !want.empty()) {
		if (used.empty()) {
			printf("%d ", *want.begin());
			want.erase(want.begin());
			continue;
		}
		if (want.empty()) {
			printf("%d ", *used.begin());
			used.erase(used.begin());
			continue;
		}
		x = *want.begin();
		y = *used.begin();
		if (x < y) {
			printf("%d ", x);
			want.erase(x);
		}
		else {
			printf("%d ", y);
			used.erase(y);
		}
	}

	/*vector<int> a1 = vector<int> (used.begin(), used.end()), a2 = vector<int>(want.begin(), want.end());
	vector<int> dd(a1.size() + a2.size());
	merge(a1.begin(), a1.end(), a2.begin(), a2.end(), dd.begin());
	for (i = 0; i < dd.size(); i++) {
		printf("%d ", dd[i]);
	}*/
	/*for (set<int>::iterator it = notused.begin(); it != notused.end(); it++) {
		printf("%d ", *it);
	}*/
	while (!used.empty() || !notused.empty()) {
		if (used.empty()) {
			printf("%d ", *notused.begin());
			notused.erase(notused.begin());
			continue;
		}
		if (notused.empty()) {
			printf("%d ", *used.begin());
			used.erase(used.begin());
			continue;
		}
		x = *notused.begin();
		y = *used.begin();
		if (x < y) {
			printf("%d ", x);
			notused.erase(x);
		}
		else {
			printf("%d ", y);
			used.erase(y);
		}
	}

	return 0;
}//ccxxgs