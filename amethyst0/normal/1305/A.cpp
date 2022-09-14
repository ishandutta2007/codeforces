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

const int maxn = 110;
int a[maxn], b[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + n);

		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

		cout << '\n';

		for (int i = 0; i < n; i++) {
			printf("%d ", b[i]);
		}

		cout << '\n';
	}
}