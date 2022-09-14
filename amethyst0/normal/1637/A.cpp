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
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>
#include <cassert>

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

		int pre = 0;

		bool ok = true;;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x < pre) {
				ok = false;
			}
			pre = x;
		}

		if (!ok) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}