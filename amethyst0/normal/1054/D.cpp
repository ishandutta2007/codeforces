#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

#define ll long long

using namespace std;

const int maxn = (int)2e5 + 10;
ll v[maxn];

int main() {
	int n, k;
	cin >> n >> k;

	ll z = ((ll)1 << k) - 1;

	ll cur = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);

		cur ^= v[i];
		v[i] = cur;
	}

	map <ll, int> m;

	m[0] = 1;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ll x = v[i];

		if (m[x] > m[x ^ z]) {
			x ^= z;
		}

		ans += i + 1 - m[x];
		m[x]++;
	}

	cout << ans << endl;

	//system("pause");
}