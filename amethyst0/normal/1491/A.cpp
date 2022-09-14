#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
int v[maxn];
int cnt[2];

int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		cnt[v[i]]++;
	}

	while (q--) {
		int tp, x;
		scanf("%d %d", &tp, &x);
		if (tp == 1) {
			x--;
			cnt[v[x]]--;
			v[x] ^= 1;
			cnt[v[x]]++;
		}
		else {
			if (cnt[1] >= x) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
}