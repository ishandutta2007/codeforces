#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 5010;
int v[maxn];
int p[maxn];

int getp(int x) {
	return (p[x] == x ? p[x] : p[x] = getp(p[x]));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			p[i] = i;
		}

		p[n] = n;

		ll ans = 0;

		for (int i = 0; i < n; i++) {
			if (v[i] > n) {
				ans += v[i] - n;
				v[i] = n;
			}

			while (v[i] > 1) {
				ans++;
				int pos = i;
				while (pos < n) {
					if (v[pos] == 1) {
						int x = getp(pos);
						if (x == pos) {
							p[pos] = pos + 1;
						}
						pos = getp(pos);
						continue;
					}
					int npos = pos + v[pos];
					v[pos]--;
					v[pos] = max(v[pos], 1);
					pos = npos;
				}
			}
		}

		printf("%lld\n", ans);
	}
}