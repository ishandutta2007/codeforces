//#pragma comment(linker, "/STACK:1000000000")
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

using namespace std;

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, a, b;

		scanf("%d %d %d", &n, &a, &b);

		int x = -1;
		int y = -1;

		for (int i = 0; i < a; i++) {
			int f;

			scanf("%d", &f);
			x = max(f, x);
		}

		for (int i = 0; i < b; i++) {
			int f;

			scanf("%d", &f);
			y = max(y, f);
		}

		if (x > y) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}