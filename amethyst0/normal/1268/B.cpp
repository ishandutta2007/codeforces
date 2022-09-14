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
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int cnt[2];

int main() {
	int n;

	cin >> n;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		if (x % 2 == 0) {
			ans += x / 2;
		}
		else {
			ans += x / 2;
			cnt[i & 1]++;
		}
	}

	cout << ans + min(cnt[0], cnt[1]) << '\n';
}