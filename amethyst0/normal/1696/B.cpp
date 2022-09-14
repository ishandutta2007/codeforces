#pragma comment(linker, "/STACK:1000000000")
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
#include <random>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		int prev = 0;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);

			if (x != 0 && prev == 0) {
				ans++;
			}
			prev = x;
		}

		printf("%d\n", min(ans, 2));
	}
}