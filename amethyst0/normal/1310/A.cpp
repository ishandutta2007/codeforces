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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = (int)2e5 + 10;
int v[maxn];
int t[maxn];

set <pii> s;

void add(int pos) {
	auto it = s.insert(mp(pos, pos)).first;

	if (it != s.begin()) {
		auto nit = prev(it);

		if (nit->second == it->first - 1) {
			int l = nit->first;
			int r = it->second;
			s.erase(nit);
			s.erase(it);
			it = s.insert(mp(l, r)).first;
		}
	}

	auto nit = next(it);

	if (nit != s.end()) {
		if (nit->first - 1 == it->second) {
			int l = it->first;
			int r = nit->second;
			s.erase(it);
			s.erase(nit);
			s.insert(mp(l, r));
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}

	vector <int> p;

	for (int i = 0; i < n; i++) {
		p.push_back(i);
	}

	sort(all(p), [&](int a, int b) {
		return t[a] > t[b];
	});

	ll ans = 0;

	for (int i : p) {
		int pos = v[i];
		int c = t[i];

		auto it = s.lower_bound(mp(pos + 1, pos));

		if (it == s.begin()) {
			add(pos);
		}
		else {
			it--;

			int to = pos;

			if (it->second >= pos) {
				to = it->second + 1;
			}

			ans += (ll)(to - pos) * c;
			add(to);
		}
	}

	cout << ans << '\n';
}