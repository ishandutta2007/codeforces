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

const int maxn = 1010;
int v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> v;
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x == 1) {
				v.push_back(1);
			}
			else {
				while (v.back() + 1 != x) {
					v.pop_back();
				}

				v.back()++;
			}

			bool fir = true;
			for (int x : v) {
				if (fir) {
					fir = false;
				}
				else {
					printf(".");
				}
				printf("%d", x);
			}
			printf("\n");
		}
	}
}