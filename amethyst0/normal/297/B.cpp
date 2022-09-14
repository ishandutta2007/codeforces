#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;

int a[maxn], b[maxn];

int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	sort(b, b + m);

	int pos = 0;

	for (int i = 0; i < n; i++) {
		while (pos < m && b[pos] < a[i]) {
			pos++;
		}

		if (pos == m) {
			printf("YES\n");
			return 0;
		}

		pos++;
	}

	printf("NO\n");

	//system("pause");
}