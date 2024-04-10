/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)3e5 + 10, mod = (int)1e9 + 7;
int v[maxn];
ll st[maxn];

int main() {
	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * 2 % mod;
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans += v[i] * st[i] - v[i] * st[n - i - 1];
		ans %= mod;

		if (ans < 0) {
			ans += mod;
		}
	}

	cout << ans << endl;

	return 0;
}