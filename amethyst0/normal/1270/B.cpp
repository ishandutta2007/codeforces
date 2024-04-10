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

const int maxn = (int)2e5 + 10;
int v[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		bool ok = false;

		for (int i = 0; i < n - 1; i++) {
			if (abs(v[i] - v[i + 1]) > 1) {
				printf("YES\n%d %d\n", i + 1, i + 2);
				ok = true;
				break;
			}
		}

		if (!ok) {
			printf("NO\n");
		}
	}

	return 0;
}