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

const int maxn = (int)2e5 + 10;
int v[maxn];

bool used[maxn];
int ans[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			used[i] = false;
		}

		vector <int> a, b, c;

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			v[i]--;
			if (v[i] != i && !used[v[i]]) {
				used[v[i]] = true;
				c.push_back(i);
			}
			else {
				a.push_back(i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				b.push_back(i);
			}
		}

		if ((int)a.size() == 1 && a[0] == b[0]) {
			a.clear();
			b.clear();
			c.clear();

			for (int i = 0; i < n; i++) {
				used[i] = false;
			}

			for (int i = n - 1; i >= 0; i--) {
				if (v[i] != i && !used[v[i]]) {
					used[v[i]] = true;
					c.push_back(i);
				}
				else {
					a.push_back(i);
				}
			}

			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					b.push_back(i);
				}
			}
		}

		if ((int)a.size() == 1 && a[0] == b[0]) {
			a.push_back(c.back());
			b.push_back(v[c.back()]);
			c.pop_back();
		}

		for (int x : c) {
			ans[x] = v[x];
		}

		sort(all(a));
		sort(all(b));

		int pos = 0;

		set <int> s;

		for (int x : a) {
			while (pos < (int)b.size() && b[pos] < x) {
				pos++;
			}

			if (pos < (int)b.size() && b[pos] == x) {
				s.insert(x);
			}
		}

		vector <int> aa, bb;

		for (int i = 0; i < (int)a.size(); i++) {
			if (!s.count(a[i])) {
				aa.push_back(a[i]);
			}

			if (!s.count(b[i])) {
				bb.push_back(b[i]);
			}
		}

		for (int x : s) {
			aa.push_back(x);
			bb.push_back(x);
		}

		for (int i = 0; i < (int)aa.size(); i++) {
			ans[aa[i]] = bb[(i + 1) % (int)bb.size()];
		}

		printf("%d\n", (int)c.size());

		for (int i = 0; i < n; i++) {
			printf("%d ", ans[i] + 1);
		}
		printf("\n");
	}
}