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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = 110;
int v[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, d;
		scanf("%d %d", &n, &d);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		int ans = v[0];

		for (int i = 1; i < n; i++) {
			int can = d / i;
			ans += min(can, v[i]);
			d -= min(can, v[i]) * i;
		}

		printf("%d\n", ans);
	}
	
	return 0;
}