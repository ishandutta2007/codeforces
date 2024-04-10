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
int v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		scanf("%d %lld", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		
		sort(v, v + n);
		
		int pos = 0;
		bool ok = false;
		
		for (int i = 0; i < n; i++) {
			while (pos < n && v[i] - v[pos] > k) {
				pos++;
			}
			
			if (pos != n && v[i] - v[pos] == k && pos != i) {
				ok = true;
				break;
			}
		}
		
		if (ok) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}