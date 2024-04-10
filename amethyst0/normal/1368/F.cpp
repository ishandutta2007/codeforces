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

const int maxn = (int)1010;

bool used[maxn];

int main() {
	int n;

	cin >> n;

	int best = 0;
	int ans = 0;

	for (int k = 2; k <= n; k++) {
		memset(used, 0, sizeof used);
		int tot = 0;

		for (int i = 0; i < n; i++) {
			if ((i % k) == k - 1) {
				continue;
			}

			used[i] = true;
			tot++;
		}

		if (used[n - 1]) {
			tot--;
			used[n - 1] = false;
		}

		tot = tot - k + 1;

		if (best < tot) {
			best = tot;
			ans = k;
		}
	}

	int k = ans;

	if (best == 0) {
		cout << 0 << endl;
		return 0;
	}

	memset(used, 0, sizeof used);

	for (int i = 0; i < n; i++) {
		if ((i % k) == k - 1) {
			continue;
		}

		used[i] = true;
	}

	if (used[n - 1]) {
		used[n - 1] = false;
	}

	vector <int> g;

	for (int i = 0; i < n; i++) {
		if (used[i]) {
			g.push_back(i);
		}
	}

	memset(used, 0, sizeof used);

	int cur = 0;

	while (cur != best) {
		vector <int> f;

		for (int x : g) {
			if (!used[x]) {
				f.push_back(x);
				if ((int)f.size() == k) {
					break;
				}
			}
		}

		cout << f.size() << ' ';

		for (int x : f) {
			used[x] = true;
			cur++;
			cout << x + 1 << ' ';
		}

		cout << endl;

		int p;
		cin >> p;
		p--;

		for (int i = 0; i < k; i++) {
			if (used[p]) {
				cur--;
				used[p] = false;
			}

			p++;
			if (p == n) {
				p = 0;
			}
		}
	}

	cout << 0 << endl;
}