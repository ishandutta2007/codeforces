#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
char a[maxn], b[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;
		scanf("%d", &n);

		scanf("%s %s", a, b);

		vector <int> ans;

		int l = 0;
		int r = n - 1;
		int fl = 0;

		for (int i = n - 1; i >= 0; i--) {
			if ((a[r] ^ fl) == b[i]) {
				if (l < r) {
					r--;
				}
				else {
					r++;
				}

				continue;
			}

			if ((a[l] ^ fl ^ 1) == b[i]) {
				ans.push_back(i + 1);
			}
			else {
				ans.push_back(1);
				ans.push_back(i + 1);
			}

			fl ^= 1;
			swap(l, r);
			if (l < r) {
				r--;
			}
			else {
				r++;
			}
		}

		printf("%d ", (int)ans.size());

		for (int x : ans) {
			printf("%d ", x);
		}

		printf("\n");
	}
}