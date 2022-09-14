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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)2e5 + 10;

int a[maxn], b[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		b[i]--;
	}

	reverse(b, b + n);

	int pos = -1;

	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			pos = i;
		}
	}

	bool fl = true;

	for (int i = pos; i >= 0; i--) {
		if (i + b[i] != pos) {
			fl = false;
		}
	}

	if (fl) {
		for (int i = pos + 1; i < n; i++) {
			if (b[i] > pos) {
				int ds = n - i;

				int x = b[i] - pos - 1;

				if (ds > x) {
					fl = false;
				}
			}
		}

		if (fl) {
			cout << n - 1 - pos << endl;
			//system("pause");
			return 0;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (b[i] >= 0) {
			int ds = n - i;

			int x = b[i];

			ans = max(ans, ds - x);
		}
	}

	ans += n;

	cout << ans << endl;

	//system("pause");
}