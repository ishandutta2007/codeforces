#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e5 + 10;
ll v[maxn];
ll ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	sort(v, v + n);

	int q;

	cin >> q;

	vector <pair <ll, int> > w;

	for (int i = 0; i < q; i++) {
		ll lm, rm;
		
		scanf("%lld %lld", &lm, &rm);

		rm -= lm;

		w.push_back(mp(rm, i));
	}

	sort(w.begin(), w.end());

	set <pair <ll, int> > s;

	for (int i = 0; i < n - 1; i++) {
		s.insert(mp(v[i + 1] - v[i], i));
	}

	ll res = 0;

	for (int i = 0; i < (int)w.size(); i++) {
		ll d = w[i].first;

		while (!s.empty() && s.begin()->first <= d) {
			res += s.begin()->first;
			s.erase(s.begin());
		}

		ans[w[i].second] = res + ((ll)s.size() + 1) * (d + 1);
	}

	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}

	//system("pause");

	return 0;
}