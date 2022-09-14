#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)4e5 + 10, maxlog = 25;
int v[maxn];
vector <int> g[2];

int main() {
	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0;

	for (int b = 0; b < maxlog; b++) {
		g[0].clear();
		g[1].clear();

		for (int i = 0; i < n; i++) {
			g[(v[i] >> b) & 1].push_back(v[i] & ((1 << b) - 1));
		}

		int tot = (1 << b);

		sort(all(g[0]));
		sort(all(g[1]));

		int pos = (int)g[1].size() - 1;

		ll cnt = 0;

		for (int i = 0; i < (int)g[0].size(); i++) {
			while (pos >= 0 && g[1][pos] + g[0][i] >= tot) {
				pos--;
			}

			cnt += pos + 1;
		}

		for (int it = 0; it < 2; it++) {
			int pos = 0;

			for (int i = (int)g[it].size() - 1; i >= 0; i--) {
				while (pos < (int)g[it].size() && g[it][i] + g[it][pos] < tot) {
					pos++;
				}

				if (i < pos) {
					cnt += (int)g[it].size() - pos;
				}
				else {
					cnt += (int)g[it].size() - i - 1;
				}
			}
		}

		if (cnt & 1) {
			ans += (1 << b);
		}
	}

	cout << ans << '\n';
}