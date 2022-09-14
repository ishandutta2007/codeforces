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
int v[maxn];

const int inf = (int)1e9 + 7;

map <pii, int> s;

int n;

int solve(int h, int w, int a, int b) {
	queue <pii> q;

	q.push(mp(h, w));

	s[mp(h, w)] = 0;

	while (!q.empty()) {
		h = q.front().first;
		w = q.front().second;

		q.pop();
		int pos = s[mp(h, w)];

		if (h >= a && w >= b) {
			return pos;
		}

		if (h >= b && w >= a) {
			return pos;
		}

		if (pos == n) {
			continue;
		}

		int hh = inf;

		if (h <= inf / v[pos]) {
			hh = h * v[pos];
		}

		int ww = w;

		if (!s.count(mp(hh, ww))) {
			s[mp(hh, ww)] = pos + 1;
			q.push(mp(hh, ww));
		}

		ww = inf;

		if (w <= inf / v[pos]) {
			ww = w * v[pos];
		}

		hh = h;

		if (!s.count(mp(hh, ww))) {
			s[mp(hh, ww)] = pos + 1;
			q.push(mp(hh, ww));
		}
	}

	return -1;
}

int main() {
	int a, b, h, w;

	cin >> a >> b >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);
	reverse(v, v + n);

	int ans = solve(h, w, a, b);

	cout << ans << endl;

	return 0;
}