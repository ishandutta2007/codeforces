//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

string s;
const int maxn = (int)1e5 + 1;
const int maxlog = 19;

struct vt {
	int w[26];
	vector <int> lnk[26];
	vector <int> rlnk[26];
	string s;

	vt() {

	}

	vt(string s) : s(s) {

	}

	int get_cnt(int l, int r) {
		int ans = 0;

		for (int i = 0; i < 26; i++) {
			if (lnk[i][r] >= l || i == s[r] - 'a') {
				ans++;
			}
		}

		return ans - 1;
	}

	vector <ll> sum[1][26];
	vector <pii> tab[1][26];

	void build() {
		memset(w, -1, sizeof w);

		for (int i = 0; i < 26; i++) {
			lnk[i].resize(s.size());
			rlnk[i].resize(s.size());

			for (int j = 0; j < 1; j++) {
				sum[j][i].resize(s.size());
				tab[j][i].resize(s.size());
			}
		}

		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = 0; j < 26; j++) {
				lnk[j][i] = w[j];
			}

			w[s[i] - 'a'] = i;
		}

		for (int j = 0; j < 26; j++) {
			w[j] = (int)s.size() - 1;
		}

		for (int i = (int)s.size() - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				rlnk[j][i] = w[j];
			}

			w[s[i] - 'a'] = i;
		}

		for (int i = 0; i < (int)s.size(); i++) {
			vector <int> g;

			for (int j = 0; j < 26; j++) {
				if (j != s[i] - 'a') {
					g.push_back(lnk[j][i]);
				}
				else {
					g.push_back(i);
				}
			}

			sort(g.rbegin(), g.rend());

			int rm = i;

			for (int j = 0; j < (int)g.size(); j++) {
				if (g[j] == -1) {
					tab[0][j][i] = tab[0][j - 1][i];
					sum[0][j][i] = sum[0][j - 1][i];
					continue;
				}

				rm = max(rm, rlnk[s[g[j]] - 'a'][g[j]]);
				int lm = g[j];

				int cnt = get_cnt(lm, rm);

				tab[0][j][i] = mp(cnt, rm);
				sum[0][j][i] = rm;
			}
		}
	}

	vector <ll> sums[maxlog];
	vector <int> tot[maxlog];
	vector <int> tabs[maxlog];

	void build(int k) {
		for (int i = 0; i < maxlog; i++) {
			sums[i].assign(s.size(), 0);
			tabs[i].assign(s.size(), -1);
			tot[i].assign(s.size(), 0);
		}

		for (int i = 0; i < (int)s.size(); i++) {
			if (tab[0][k][i].first == k) {
				sums[0][i] = tab[0][k][i].second;
				tabs[0][i] = tab[0][k][i].second;
				tot[0][i] = 1;
			}
			else {
				sums[0][i] = 0;
				tabs[0][i] = i;
				tot[0][i] = 0;
			}
		}

		for (int it = 1; it < maxlog; it++) {
			for (int i = 0; i < (int)s.size(); i++) {
				tabs[it][i] = tabs[it - 1][tabs[it - 1][i]];
				sums[it][i] = sums[it - 1][i] + sums[it - 1][tabs[it - 1][i]];
				tot[it][i] = tot[it - 1][i] + tot[it - 1][tabs[it - 1][i]];
			}
		}
	}
};

ll stup(int pos) {
	int lm = pos;
	int rm = pos;
	int n = (int)s.size();
	ll ans = 0;

	while (rm - lm + 1 != n) {
		ans += n - 1 - (rm - lm);

		int mask = 0;

		for (int i = lm; i <= rm; i++) {
			mask |= (1 << (s[i] - 'a'));
		}

		int l = lm;

		while (lm > 0 && mask != 0) {
			lm--;
			int c = s[lm] - 'a';

			if ((mask >> c) & 1) {
				mask ^= (1 << c);
			}
		}

		mask = 0;

		for (int i = l; i <= rm; i++) {
			mask |= (1 << (s[i] - 'a'));
		}

		while (rm < n - 1 && mask != 0) {
			rm++;
			int c = s[rm] - 'a';

			if ((mask >> c) & 1) {
				mask ^= (1 << c);
			}
		}
	}

	return ans;
}

int main() {
	cin >> s;
	for (int i = 0; i < (int)1e4; i++) {
		//s.push_back(rand() % 26 + 'a');
	}

	vt dpr = vt(s);
	dpr.build();
	reverse(s.begin(), s.end());
	vt dpl = vt(s);
	dpl.build();
	reverse(s.begin(), s.end());

	ll ans = 0;
	ll pre = 0;

	int n = (int)s.size();

	vector <pii> cur;

	for (int i = 0; i < (int)s.size(); i++) {
		cur.push_back(mp(n - 1 - i, i));
		ans += n - 1;
	}

	for (int j = 0; j < 26; j++) {
		dpr.build(j);
		dpl.build(j);

		for (int i = 0; i < (int)s.size(); i++) {
			int lm = cur[i].first;
			int rm = cur[i].second;

			int cnt = dpr.get_cnt(n - 1 - lm, rm);

			if (cnt == j) {
				for (int it = maxlog - 1; it >= 0; it--) {
					if (dpr.tot[it][rm] == (1 << it) && dpl.tot[it][lm] == (1 << it)) {
						ans -= dpr.sums[it][rm];
						rm = dpr.tabs[it][rm];
						ans -= dpl.sums[it][lm];
						ans += 2ll * (n - 1) * (1 << it);
						lm = dpl.tabs[it][lm];
					}
				}

				rm = dpr.tab[0][cnt][rm].second;
				lm = dpl.tab[0][cnt][lm].second;
				ans -= rm + lm;
				ans += 2 * (n - 1);

				cur[i].first = lm;
				cur[i].second = rm;
			}
		}
	}

	cout << ans << endl;
}