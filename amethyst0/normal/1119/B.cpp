#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e3 + 10;
int v[maxn];

int h;

bool solve(int n) {
	vector <int> g;

	for (int i = 0; i < n; i++) {
		g.push_back(v[i]);
	}

	sort(g.begin(), g.end());

	ll ans = 0;

	for (int i = (int)g.size() - 1; i >= 0; i -= 2) {
		ans += g[i];
	}

	return ans <= h;
}

int main() {
	int n;

	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int l = 1;
	int r = n;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (solve(m)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	cout << l << endl;

	//system("pause");

	return 0;
}