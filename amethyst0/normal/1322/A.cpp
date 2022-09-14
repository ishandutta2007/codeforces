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

const int maxn = (int)1e6 + 10;
char s[maxn];

int main() {
	int n;
	cin >> n;
	scanf("%s", s);

	int bal = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			bal++;
		}
		else {
			bal--;
		}
	}

	if (bal != 0) {
		cout << -1 << '\n';
		return 0;
	}

	int cur = 0;
	int pos = 0;
	int ans = 0;

	for (int i = 0; i < n; ) {
		if (s[i] == '(') {
			cur++;
		}
		else {
			cur--;
		}

		int r = i + 1;

		while (cur < 0) {
			if (s[r] == '(') {
				cur++;
			}
			else {
				cur--;
			}

			r++;
		}

		if (i + 1 < r)
			ans += r - i;
		i = r;
	}

	cout << ans << '\n';
}