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

const int maxn = (int)1e5 + 10;

int v[maxn];
ll sum[maxn];
ll ans[maxn];

ll get_sum(int a, int b) {
	if (a == 0) {
		return sum[b];
	}

	return sum[b] - sum[a - 1];
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		sum[i] = v[i];

		if (i != 0) {
			sum[i] += sum[i - 1];
		}
	}

	set <pii> s;
	multiset <ll> q;

	s.insert(mp(n - 1, 0));
	q.insert(sum[n - 1]);

	for (int i = 0; i < n; i++) {
		int p;

		scanf("%d", &p);
		p--;
		
		auto it = s.lower_bound(mp(p, -1));

		q.erase(q.find(get_sum(it->second, it->first)));

		if (it->second != p) {
			q.insert(get_sum(it->second, p - 1));
			s.insert(mp(p - 1, it->second));
		}
		
		if (it->first != p) {
			q.insert(get_sum(p + 1, it->first));
			s.insert(mp(it->first, p + 1));
		}

		s.erase(it);
		
		if (!q.empty()) {
			printf("%lld\n", *q.rbegin());
		} else {
			printf("0\n");
		}
	}

	return 0;
}