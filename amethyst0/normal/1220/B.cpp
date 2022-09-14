#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long

const int maxn = (int)1e3 + 10;
int v[maxn][maxn];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	ll x = (ll)v[0][1] * v[0][2];
	x /= v[1][2];

	ll l = 1;
	ll r = (int)1e9;

	while (l != r) {
		ll m = (l + r) >> 1;

		if (m * m < x) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	cout << l << ' ';

	for (int i = 1; i < n; i++) {
		printf("%lld ", v[0][i] / l);
	}

	//system("pause");

	return 0;
}