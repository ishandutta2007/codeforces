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

const int maxn = (int)1e5 + 10;
int a[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll x;
		scanf("%lld", &x);
		
		ll st = 1;
		
		while (x % 2 == 0) {
			x /= 2;
			st *= 2;
		}
		
		if (x == 1) {
			printf("-1\n");
			continue;
		}
		
		if (x >= st * 2 + 1) {
			printf("%lld\n", 2 * st);
		} else {
			printf("%lld\n", x);
		}
	}
}