/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
vector <pii> a, b;
vector <pii> f, e;

int main() {
	int n, c, d;

	cin >> n >> c >> d;

	for (int i = 0; i < n; i++) {
		int bb, p;
		char c;

		scanf("%d %d %c", &bb, &p, &c);

		if (c == 'C') {
			a.push_back(mp(bb, p));
		} else {
			b.push_back(mp(bb, p));
		}
	}

	int maxa = 0;
	int maxb = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].second <= c) {
			maxa = max(maxa, a[i].first);
		}
	}

	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i].second <= d) {
			maxb = max(maxb, b[i].first);
		}
	}

	int ans = 0;

	if (maxa != 0 && maxb != 0) {
		ans = max(ans, maxa + maxb);
	}

	for (int i = 0; i < (int)a.size(); i++) {
		swap(a[i].first, a[i].second);
	}

	for (int i = 0; i < (int)b.size(); i++) {
		swap(b[i].first, b[i].second);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	pii now = mp(0, 0);

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].second > now.first) {
			now.second = now.first;
			now.first = a[i].second;
		} else if (a[i].second > now.second) {
			now.second = a[i].second;
		}

		e.push_back(now);
	}

	now = mp(0, 0);

	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i].second > now.first) {
			now.second = now.first;
			now.first = b[i].second;
		} else if (b[i].second > now.second) {
			now.second = b[i].second;
		}

		f.push_back(now);
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].first > c) {
			break;
		}

		int pos = lower_bound(a.begin(), a.end(), mp(c - a[i].first + 1, 0)) - a.begin();

		pos--;

		if (pos != -1) {
			if (e[pos].first != a[i].second) {
				ans = max(ans, a[i].second + e[pos].first);
			} else if (e[pos].second != 0) {
				ans = max(ans, a[i].second + e[pos].second);
			}
		}
	}

	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i].first > d) {
			break;
		}

		int pos = lower_bound(b.begin(), b.end(), mp(d - b[i].first + 1, 0)) - b.begin();

		pos--;

		if (pos != -1) {
			if (f[pos].first != b[i].second) {
				ans = max(ans, b[i].second + f[pos].first);
			} else if (f[pos].second != 0) {
				ans = max(ans, b[i].second + f[pos].second);
			}
		}
	}

	cout << ans << endl;

	return 0;
}