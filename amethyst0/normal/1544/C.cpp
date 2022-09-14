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
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

deque <int> a, b;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		vector <int> aa, bb;

		ll suma = 0;
		ll sumb = 0;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			aa.push_back(x);
			suma += x;
		}

		sort(all(aa));

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			bb.push_back(x);
			sumb += x;
		}

		sort(all(bb));

		int l = 0;
		int r = n;

		while (l != r) {
			int m = (l + r) >> 1;

			a = deque<int>(all(aa));
			b = deque<int>(all(bb));
			ll cura = suma, curb = sumb;

			for (int i = 0; i < m; i++) {
				a.push_back(100);
				cura += 100;
				b.push_front(0);
			}

			int tot = n + m;
			tot -= tot / 4;
			while (a.size() > tot) {
				cura -= a.front();
				a.pop_front();
			}

			while (b.size() > tot) {
				curb -= b.front();
				b.pop_front();
			}

			if (cura >= curb) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}

		printf("%d\n", l);
	}
}