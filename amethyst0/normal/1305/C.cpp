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

const int maxn = (int)2e5 + 10;

int n, m;
int v[maxn];
const int maxm = 1010;

int cnt[maxm];

int mul(int x, int y) {
	return (ll)x * y % m;
}

int my_pow(int x, ll y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		y >>= 1;
		x = mul(x, x);
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		cnt[v[i] % m]++;
	}

	int ans = 1;

	for (int i = 0; i < m; i++) {
		if (cnt[i] > 1) {
			ans = 0;
			break;
		}
	}

	if (ans > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = mul(ans, abs(v[i] - v[j]));
			}
		}
	}

	cout << ans << '\n';
}