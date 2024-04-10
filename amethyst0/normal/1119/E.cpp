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

const int maxn = (int)3e5 + 10;
ll v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	ll cnt = 0;
	ll ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		cnt += v[i] / 2;
		if (v[i] % 2 == 1 && cnt != 0) {
			ans++;
			cnt--;
		}
	}

	ans += 2 * (cnt / 3);
	cnt %= 3;
	if (cnt == 2) {
		ans++;
	}

	cout << ans << endl;

	//system("pause");

	return 0;
}