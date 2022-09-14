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

const int maxn = (int)1e6 + 10;

int sum[maxn];

int c;

bool check(int l, int r) {
	if (l > c) {
		return false;
	}
	r = min(r, c);
	
	if (l == 0) {
		return sum[r] > 0;
	}
	
	return sum[r] - sum[l - 1] > 0;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		scanf("%d %d", &n, &c);
		
		for (int i = 0; i <= c; i++) {
			sum[i] = 0;
		}
		
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			
			sum[x]++;
		}
		
		for (int i = 1; i <= c; i++) {
			sum[i] += sum[i - 1];
		}
		
		bool ok = true;
		
		for (int i = 1; i <= c; i++) {
			if (!check(i, i)) {
				continue;
			}
			
			for (int j = 1; j * i <= c; j++) {
				if (check(j * i, i * (j + 1) - 1)) {
					if (!check(j, j)) {
						ok = false;
						break;
					}
				}
			}
			
			if (!ok) {
				break;
			}
		}
		
		if (ok) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}