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
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int hp[2], dt[2], l[2], r[2];
ld p[2];

const int maxn = 201;

ld dp[2][maxn][22];
bool us[2][maxn][22];

ld f[65][23][23];
bool in[65][23][23];

inline ld go(int it, int hp, int cnt) {
	if (hp <= 0) {
		return 0;
	}

	if (us[it][hp][cnt]) {
		return dp[it][hp][cnt];
	}

	us[it][hp][cnt] = true;
	
	if (cnt == 0) {
		return dp[it][hp][cnt] = 1;
	}

	for (int i = l[it]; i <= r[it]; i++) {
		dp[it][hp][cnt] += go(it, hp - i, cnt - 1);
	}

	dp[it][hp][cnt] /= (r[it] - l[it] + 1);
	return dp[it][hp][cnt];
}

int main() {
	for (int i = 0; i < 2; i++) {
		cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> p[i];
		p[i] /= 100;
	}

	if (p[0] == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (p[1] == 1) {
		cout << 1 << endl;
		return 0;
	}

	vector <pii> g;

	for (int i = 0; i < dt[0]; i++) {
		g.push_back(mp(i * dt[1], 1));
	}

	for (int i = 0; i < dt[1]; i++) {
		g.push_back(mp(i * dt[0], 0));
	}

	sort(g.begin(), g.end());

	queue <pair <pii, int> > q;

	q.push(mp(mp(0, 0), 0));
	in[0][0][0] = true;
	f[0][0][0] = 1.0;

	ld ans = 0;

	int maxx = (int)2.71e6;

	for (int i = 0; i < maxx && !q.empty(); i++) {
	    if (!(i & 1023)) {
	        if (clock() > 0.97 * CLOCKS_PER_SEC) {
	            break;
	        }
	    }
		int c1 = q.front().first.first;
		int c2 = q.front().first.second;
		int pos = q.front().second;

		ld pp = f[pos][c1][c2];
		f[pos][c1][c2] = 0;
		in[pos][c1][c2] = false;
		q.pop();

		if (go(0, hp[1], c1) == 0 || go(1, hp[0], c2) == 0) {
			continue;
		}

		if (pp == 0) {
			continue;
		}
		
		if (g[pos].second == 0) {
			int nex = pos + 1;
			if (nex == (int)g.size()) {
				nex = 0;
			}

			f[nex][c1][c2] += pp * p[0];

			if (!in[nex][c1][c2]) {
				in[nex][c1][c2] = true;
				q.push(mp(mp(c1, c2), nex));
			}
			
			ld z = pp * (1 - p[0]);

			f[nex][c1 + 1][c2] += z;

			if (!in[nex][c1 + 1][c2]) {
				in[nex][c1 + 1][c2] = true;
				q.push(mp(mp(c1 + 1, c2), nex));
			}

			ans += (go(0, hp[1], c1) - go(0, hp[1], c1 + 1)) * z * go(1, hp[0], c2);
		} else {
			int nex = pos + 1;
			if (nex == (int)g.size()) {
				nex = 0;
			}

			f[nex][c1][c2] += pp * p[1];

			if (!in[nex][c1][c2]) {
				in[nex][c1][c2] = true;
				q.push(mp(mp(c1, c2), nex));
			}

			f[nex][c1][c2 + 1] += pp * (1 - p[1]);

			if (!in[nex][c1][c2 + 1]) {
				in[nex][c1][c2 + 1] = true;
				q.push(mp(mp(c1, c2 + 1), nex));
			}
		}
	}

	printf("%.10lf\n", ans);

	return 0;
}