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

const int maxn = (int)1e5 + 10;

char s[maxn];

int main() {
	int t;

	cin >> t;
	while (t--) {
		int n;

		scanf("%d", &n);

		if (n == 1) {
			printf("-1\n");
			continue;
		}

		for (int i = 0; i < n - 1; i++) {
			s[i] = '2';
		}

		s[n - 1] = '3';

		int sum = 2 * (n - 1);
		sum %= 3;

		if (sum == 0) {
			s[n - 2] = '3';
		}

		s[n] = 0;

		printf("%s\n", s);
	}
}