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
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

bool is_prime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		ll a, b;

		cin >> a >> b;

		if (b != a - 1) {
			cout << "NO\n";
			continue;
		}

		a = 2 * a - 1;

		if (is_prime(a)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	//system("pause");
}