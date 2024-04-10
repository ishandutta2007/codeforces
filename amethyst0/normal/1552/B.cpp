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
#include <cstdio>
#include <cassert>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> v[maxn];

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		scanf("%d", &n);

		int pos = 0;

		for (int i = 0; i < n; i++) {
			v[i].resize(5);
			int tot = 0;

			for (int j = 0; j < 5; j++) {
				scanf("%d", &v[i][j]);
				if (v[i][j] < v[pos][j]) {
					tot++;
				}
			}

			if (tot >= 3) {
				pos = i;
			}
		}

		for (int i = 0; i < n; i++) {
			int tot = 0;

			for (int j = 0; j < 5; j++) {
				if (v[i][j] < v[pos][j]) {
					tot++;
				}
			}

			if (tot >= 3) {
				pos = -2;
				break;
			}
		}

		printf("%d\n", pos + 1);
	}
}