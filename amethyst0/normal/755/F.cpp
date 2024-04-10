/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
vector <int> d;
bool used[maxn];
int v[maxn];

int go(int x) {
	used[x] = true;

	if (used[v[x]]) {
		return 1;
	}

	return 1 + go(v[x]);
}

bitset <maxn / 2> b;
int w[maxn / 2];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			d.push_back(go(i));
		}
	}

	sort(d.begin(), d.end());

	int l = 0;

	int kk = k;

	if (k > n / 2) {
		k = n - k;
	}

	b[k] = 1;

	for (int i = 0; i < (int)d.size(); i++) {
		if (d[i] >= 1000) {
			b |= b >> d[i];
		}
	}

	if (!b[0]) {
		memset(w, -1, sizeof w);
		sort(d.begin(), d.end());
		for (int i = 0; i < (int)d.size(); ) {
			if (d[i] < 1000) {
				int cnt = 0;

				int pos = i;

				while (pos < (int)d.size() && d[pos] == d[i]) {
					cnt++;
					pos++;
				}

				int x = d[i];
				for (int j = k; j >= x; j--) {
					if (b[j] && w[j] != i) {
						for (int h = j - x; h >= max(0, j - x * cnt); h -= x) {
							if (!b[h]) {
								b[h] = 1;
								w[h] = i;
							} else {
								break;
							}
						}
					}
				}

				if (b[0]) {
					break;
				}

				i = pos;
			} else {
				break;
			}
		}
	}

	if (b[0]) {
		cout << kk << ' ';
	} else {
		cout << kk + 1 << ' ';
	}

	k = kk;

	int r = 0;

	for (int i = 0; i < (int)d.size(); i++) {
		if (k < d[i] / 2) {
			r += 2 * k;
			k = 0;
		} else {
			r += d[i] / 2 * 2;
			k -= d[i] / 2;
		}
	}

	for (int i = 0; i < (int)d.size(); i++) {
		if (d[i] & 1) {
			if (k != 0) {
				r++;
				k--;
			}
		}
	}

	cout << r << endl;

	return 0;
}