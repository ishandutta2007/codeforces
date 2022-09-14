#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

int main() {
	int n, m;

	cin >> n >> m;

	int cnt = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			ll x = (ll)i * i + (ll)j * j;

			if (x % m == 0) {
				cnt++;
			}
		}
	}

	ll ans = (ll)(n / m) * (n / m) * cnt;

	int f = n % m;

	for (int i = 1; i <= f; i++) {
		for (int j = 1; j <= f; j++) {
			ll x = (ll)i * i + (ll)j * j;

			if (x % m == 0) {
				ans++;
			}
		}
	}

	int cn = 0;

	for (int i = 1; i <= f; i++) {
		for (int j = 1; j <= m; j++) {
			ll x = (ll)i * i + (ll)j * j;

			if (x % m == 0) {
				cn++;
			}
		}
	}

	ans += (ll)cn * (n / m) * 2;

	cout << ans << endl;

	//system("pause");
}