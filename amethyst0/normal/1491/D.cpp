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

int good[31][31];
int a, b;

int dfs(int pa, int pb) {
	if (good[pa][pb] != -1) {
		return good[pa][pb];
	}

	int x = a >> pa;
	int y = b >> pb;
	if (x == 0) {
		if (y == 0) {
			return good[pa][pb] = 1;
		}
		else {
			return good[pa][pb] = 0;
		}
	}

	if (y == 0) {
		return good[pa][pb] = 0;
	}

	if (!(x & 1)) {
		return good[pa][pb] = dfs(pa + 1, pb);
	}

	if (!(y & 1)) {
		return good[pa][pb] = dfs(pa, pb + 1);
	}

	if (pa > pb) {
		return good[pa][pb] = 0;
	}

	if (pa == pb) {
		return good[pa][pb] = dfs(pa + 1, pb + 1);
	}

	int ok = 0;

	for (int i = pa + 1; i <= pb; i++) {
		ok |= dfs(i, pb + 1);
	}

	return good[pa][pb] = ok;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		scanf("%d %d", &a, &b);
		memset(good, -1, sizeof good);

		if (dfs(0, 0)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}