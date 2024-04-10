/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

const int maxn = (int)2e5 + 10;
ll v[maxn];
int num[maxn];

bool cmp(int a, int b) {
	return v[a] < v[b];
}

int main() {
	int n, k;
	ll x;

	cin >> n >> k >> x;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);
		num[i] = i;
		if (v[i] < 0) {
			cnt++;
		}
	}

	if (cnt % 2 == 0) {
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (abs(v[i]) < abs(v[pos])) {
				pos = i;
			}
		}

		if (v[pos] >= 0) {
			while (k != 0 && v[pos] >= 0) {
				v[pos] -= x;
				k--;
			}
		} else {
			while (k != 0 && v[pos] < 0) {
				v[pos] += x;
				k--;
			}
		}
	}

	set <pair <ll, int> > s;

	for (int i = 0; i < n; i++) {
		s.insert(mp(abs(v[i]), i));
	}

	while (k != 0) {
		int p = s.begin()->second;
		s.erase(s.begin());

		if (v[p] >= 0) {
			v[p] += x;
		} else {
			v[p] -= x;
		}

		s.insert(mp(abs(v[p]), p));

		k--;
	}

	for (int i = 0; i < n; i++) {
		printf("%I64d ", v[i]);
	}

	return 0;
}