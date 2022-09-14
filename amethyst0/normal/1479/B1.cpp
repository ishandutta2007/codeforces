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

const int maxn = (int)1e5 + 10;
int v[maxn];
int dp[maxn];

const int inf = (int)1e9;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	pair <pii, pii> best = mp(mp(-inf, -1), mp(-inf, -1));
	dp[n] = 0;

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (i == 0 || v[i] != v[i - 1]) {
			best.first.first++;
			best.second.first++;
		}

		int cur = 0;

		if (i < 2 || v[i - 2] != v[i]) {
			cur = dp[i + 1] + 1;
		}
		else {
			cur = dp[i + 1];
		}

		if (i == 0 || v[i] != v[i - 1]) {
			cnt++;
		}

		cur = max(cur, cnt);
		if (i < 2 || best.first.second != v[i - 2]) {
			cur = max(cur, best.first.first + 1);
		}
		else {
			cur = max(cur, best.first.first);
		}

		if (i < 2 || best.second.second != v[i - 2]) {
			cur = max(cur, best.second.first + 1);
		}
		else {
			cur = max(cur, best.second.first);
		}

		dp[i] = cur;

		cur = dp[i + 1];

		if (cur > best.first.first) {
			if (best.first.second != v[i]) {
				best.second = best.first;
				best.first = mp(cur, v[i]);
			}
			else {
				best.first = mp(cur, v[i]);
			}
		}
		else if (cur > best.second.first && v[i] != best.first.second) {
			best.second = mp(cur, v[i]);
		}
	}

	cout << dp[0] << '\n';
}