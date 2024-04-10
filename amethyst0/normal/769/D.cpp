/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;

int cnt[maxn];
int v[maxn];

int main() {
	cnt[0] = 0;

	for (int i = 1; i < maxn; i++) {
		cnt[i] = (i & 1) + cnt[i >> 1];
	}

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v[x]++;
	}

	if (k == 0) {
		ll ans = 0;
		for (int i = 0; i <= (int)1e4; i++) {
			ans += (ll)v[i] * (v[i] - 1) / 2;
		}

		cout << ans << endl;
		return 0;
	}

	ll ans = 0;

	for (int i = 0; i <= (int)1e4; i++) {
		for (int j = i + 1; j <= (int)1e4; j++) {
			if (cnt[i ^ j] == k) {
				ans += (ll)v[i] * v[j];
			}
		}
	}

	cout << ans << endl;

	return 0;
}