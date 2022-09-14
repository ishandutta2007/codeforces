//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 2050 != 0) {
			cout << -1 << '\n';
			continue;
		}

		n /= 2050;
		ll ans = 0;
		while (n) {
			ans += n % 10;
			n /= 10;
		}
		cout << ans << '\n';
	}
}