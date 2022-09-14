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

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		vector<int> v = {a - 2, b - 2, a - 2, b - 2};
		
		vector <int> ans;
		
		for (int msk = 0; msk < (1 << 4); msk++) {
			auto a = v;
			for (int i = 0; i < 4; i++) {
				if ((msk >> i) & 1) {
					a[i]++;
				} else {
					a[(i + 1) % 4]++;
				}
			}
			
			int g = 0;
			
			for (int i = 0; i < 4; i++) {
				g = gcd(g, a[i]);
			}
			
			for (int i = 1; i * i <= g; i++) {
				if (g % i == 0) {
					ans.push_back(i);
					ans.push_back(g / i);
				}
			}
		}
		
		sort(all(ans));
		ans.resize(unique(all(ans)) - ans.begin());
		printf("%d", (int)ans.size());
		for (int x : ans) {
			printf(" %d", x);
		}
		printf("\n");
	}
}