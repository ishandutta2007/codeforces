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
		int n;
		scanf("%d", &n);

		cout << n / 2 * 6 << '\n';

		for (int i = 0; i < n; i += 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("1 %d %d\n", i + 1, i + 2);
			printf("1 %d %d\n", i + 1, i + 2);
			printf("2 %d %d\n", i + 1, i + 2);
			printf("1 %d %d\n", i + 1, i + 2);
			printf("1 %d %d\n", i + 1, i + 2);
			printf("2 %d %d\n", i + 1, i + 2);
		}
	}
}