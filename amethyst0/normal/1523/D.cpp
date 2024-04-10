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
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 1;
bitset<maxn> b[65];
char s[65];

mt19937 rr(time(NULL));

vector <int> ans;
int res = 0;

vector <int> g[maxn];
bitset <maxn> cur;
int cnt[1 << 15];
bool bad[65];

int main() {
	cnt[0] = 0;
	for (int i = 1; i < (1 << 15); i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n, m, p;
	cin >> n >> m >> p;
	//n = (int)2e5;
	//m = 60;
	//p = 15;

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			//s[j] = '0';
		}

		for (int j = 0; j < p; j++) {
			//int x = rr() % m;
			//s[x] = '1';
		}

		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				b[j][i] = 1;
				g[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if ((int)b[i].count() >= (n + 1) / 2 && res == 0) {
			res = 1;
			ans = { i };
		}
		else {
			bad[i] = true;
		}

		for (int j = 0; j < i; j++) {
			if ((int)(b[i] & b[j]).count() >= (n + 1) / 2 && res <= 1) {
				res = 2;
				ans = { i, j };
			}

			for (int k = 0; k < j; k++) {
				if ((int)(b[i] & b[j] & b[k]).count() >= (n + 1) / 2 && res <= 2) {
					res = 3;
					ans = { i, j, k };
				}
			}
		}
	}

	for (int it = 0; it < 10; it++) {
		int x = rr() % n;

		int l = res;
		int r = (int)g[x].size();

		while (l <= r) {
			int md = (l + r) >> 1;
			for (int ms = 1; ms < (1 << (int)g[x].size()); ms++) {
				if (cnt[ms] != md) {
					continue;
				}

				int i = -1;
				bool fir = true;
				int tot = 0;

				bool ok = true;

				for (int p : g[x]) {
					if (bad[p]) {
						//ok = false;
					}
				}

				if (!ok) {
					continue;
				}

				for (int p : g[x]) {
					i++;
					if ((ms >> i) & 1) {
						tot++;
						if (fir) {
							cur = b[p];
							fir = false;
						}
						else {
							cur &= b[p];
						}
					}
				}

				if ((int)cur.count() >= (n + 1) / 2) {
					if (tot > res) {
						res = tot;
						i = -1;
						ans.clear();
						for (int p : g[x]) {
							i++;
							if ((ms >> i) & 1) {
								ans.push_back(p);
							}
						}
					}
				}
			}

			if (res >= md) {
				l = md + 1;
			}
			else {
				r = md - 1;
			}
		}
	}

	string res(m, '0');
	for (int x : ans) {
		res[x] = '1';
	}

	cout << res << '\n';
}