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

const int maxn = (int)2e5 + 10;
ll v[maxn];
ll c[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%lld", &v[i]);
			c[i] = 0;
		}
		
		int pos = -1;
		
		for (int i = 0; i < n; i++) {
			if (v[i] != 0) {
				pos = i;
			}
		}
		
		if (pos == -1) {
			printf("Yes\n");
			continue;
		}
		
		bool ok = true;
		
		while (pos > 0) {
			if (v[pos] >= c[pos]) {
				ok = false;
				break;
			}
			
			c[pos - 1] -= v[pos] - c[pos];
			pos--;
		}
		
		if (v[0] != c[0]) {
			ok = false;
		}
		
		if (ok) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}