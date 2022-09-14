//#pragma comment(linker, "/STACK:1000000000")
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

const int maxn = (int)1e6 + 1;
int ed[maxn];
bool used[maxn];

int go(int v) {
	if (used[v]) {
		return v;
	}

	used[v] = true;

	return go(ed[v]);
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			int x;

			scanf("%d", &x);
			x += n - i + 1;
			ed[n - i + 1] = x;
		}

		for (int i = 1; i <= n; i++) {
			used[i] = false;
		}

		int v = go(1);

		int cur = v;

		vector <int> ans;

		while (true) {
			ans.push_back(n + 1 - cur);
			cur = ed[cur];
			if (cur == v) {
				break;
			}
		}

		printf("%d\n", ans.size());

		for (int x : ans) {
			printf("%d ", x);
		}

		printf("\n");
	}

	return 0;
}