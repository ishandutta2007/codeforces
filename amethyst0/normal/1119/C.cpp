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

const int maxn = 510;
int v[maxn][maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			v[i][j] ^= x;
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < m; j++) {
			cnt ^= v[i][j];
		}

		if (cnt == 1) {
			cout << "No\n";
			return 0;
		}
	}

	for (int j = 0; j < m; j++) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt ^= v[i][j];
		}

		if (cnt == 1) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";

	//system("pause");

	return 0;
}