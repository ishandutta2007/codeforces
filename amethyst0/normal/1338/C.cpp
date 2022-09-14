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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

void write(int x) {
	//cout << x << ' ';
	//return;
	while (x) {
		cout << (x & 1);
		x >>= 1;
	}

	cout << ' ';
}

int main() {
	/*set <int> s;

	int p = 1;

	int itr = 0;

	while (itr < 100) {
		itr++;
		while (s.count(p)) {
			p++;
		}

		int nx = p + 1;

		while (s.count(nx) || s.count(nx ^ p)) {
			nx++;
		}

		s.insert(p);
		s.insert(nx);
		s.insert(p ^ nx);

		write(p);
		write(nx);
		write(p ^ nx);
		cout << '\n';
	}*/

	int t;

	cin >> t;

	while (t--) {
		ll n;

		scanf("%lld", &n);

		ll pos = (n - 1) / 3 + 1;

		ll l = 1;
		ll r = 4;
		int b = 0;

		while (pos > (r - l) / 3) {
			pos -= (r - l) / 3;
			l *= 4;
			r *= 4;
			b++;
		}

		ll x = l + pos - 1;
		pos--;

		ll y = l * 2;
		ll st = 1;

		for (int i = 0; i < b; i++) {
			if (pos % 4 == 0) {

			}
			else if (pos % 4 == 1) {
				y += st * 2;
			}
			else if (pos % 4 == 2) {
				y += st * 3;
			}
			else {
				y += st;
			}

			st *= 4;
			pos /= 4;
		}

		if (n % 3 == 1) {
			printf("%lld\n", x);
		}
		else if (n % 3 == 2) {
			printf("%lld\n", y);
		}
		else {
			printf("%lld\n", (x ^ y));
		}
	}
}