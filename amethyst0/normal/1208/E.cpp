#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e6 + 10;
ll ans[maxn];
ll pref[maxn];
int v[maxn];

void add(int l, int r, int x) {
	if (l <= r) {
		pref[l] += x;
		pref[r + 1] -= x;
	}
}

int main() {
	int n, w;

	cin >> n >> w;
	//n = 1;// (int)1e6;
	//w = (int)1e6;
	
	for (int it = 0; it < n; it++) {
		int l;

		scanf("%d", &l);
		//l = w;

		for (int j = 0; j < l; j++) {
			scanf("%d", &v[j]);
			//v[j] = rand();
		}

		multiset <int> s;

		if (2 * l > w) {
			int lm = -1;
			int rm = -1;
			
			for (int i = 0; i < w; i++) {
				int curl = max(0, l - w + i);
				int curr = min(l - 1, i);

				if (i == 0) {
					s.insert(v[0]);
				}
				else {
					while (curl > lm) {
						s.erase(s.find(v[lm]));
						lm++;
					}

					while (rm < curr) {
						rm++;
						s.insert(v[rm]);
					}
				}

				lm = curl;
				rm = curr;

				int x = (*s.rbegin());

				if (x >= 0 || (i < l && i + l >= w)) {
					ans[i] += x;
				}
			}
		}
		else {
			int x = 0;
			for (int i = 0; i < l; i++) {
				x = max(x, v[i]);
				ans[i] += x;
			}

			x = 0;

			int p = w - 1;

			for (int i = l - 1; i >= 0; i--) {
				x = max(x, v[i]);
				ans[p] += x;
				p--;
			}

			add(l, p, x);
		}
	}

	for (int i = 1; i < w; i++) {
		pref[i] += pref[i - 1];
	}

	for (int i = 0; i < w; i++) {
		printf("%lld ", ans[i] + pref[i]);
	}
	
	//system("pause");
	return 0;
}