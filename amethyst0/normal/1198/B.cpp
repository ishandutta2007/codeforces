#pragma comment(linker, "/STACK:1000000000")
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
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)2e5 + 10;
int a[maxn];
int pos[maxn];
int r[maxn];

int main() {
	int n, q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	cin >> q;

	for (int i = 0; i < q; i++) {
		int tp;

		scanf("%d", &tp);

		r[i] = -1;

		if (tp == 1) {
			int p, x;

			scanf("%d %d", &p, &x);
			p--;

			a[p] = x;
			pos[p] = i;
		}
		else {
			int x;
			scanf("%d", &x);
			r[i] = x;
		}
	}

	for (int i = q - 2; i >= 0; i--) {
		r[i] = max(r[i], r[i + 1]);
	}

	for (int i = 0; i < n; i++) {
		int ps = pos[i];

		a[i] = max(a[i], r[ps]);

		printf("%d ", a[i]);
	}

	//system("pause");
}