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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;

deque <int> d;
pii ans[maxn];

int main() {
	int n, q;

	cin >> n >> q;

	int mx = 0;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		mx = max(mx, x);

		d.push_back(x);
	}

	int cnt = 0;

	for (int i = 0; i < maxn; i++) {
		int x = d.front();
		d.pop_front();
		int y = d.front();
		d.pop_front();

		if (x == mx) {
			d.push_front(y);
			break;
		}

		cnt++;

		ans[i] = mp(x, y);

		if (x < y) {
			swap(x, y);
		}

		d.push_back(y);
		d.push_front(x);
	}

	while (q--) {
		ll p;

		scanf("%lld", &p);

		p--;

		if (p < cnt) {
			printf("%d %d\n", ans[p].first, ans[p].second);
		}
		else {
			p -= cnt;

			p %= (n - 1);

			printf("%d %d\n", mx, d[p]);
		}
	}

	//system("pause");

	return 0;
}