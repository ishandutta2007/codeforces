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

string s;

int main() {
	s = "codeforces";

	int t;

	cin >> t;

	while (t--) {
		ll a, b, n;

		scanf("%lld %lld %lld", &a, &b, &n);

		int cnt = 0;

		while (max(a, b) <= n) {
			cnt++;
			if (a > b) {
				swap(a, b);
			}

			a += b;
		}

		printf("%d\n", cnt);
	}
}