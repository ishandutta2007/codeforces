#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;

int n, a, b;
multiset<ll> ms1, ms2;

ll sum = 0;

void add1(ll x) {
	sum += x;
	ms1.insert(x);
}

void rem1(ll x) {
	sum -= x;
	ms1.erase(ms1.find(x));
}

void add(ll x) {
	if (x <= 0) return;
	add1(x);
	if (ms1.size() > b) {
		ms2.insert(*ms1.begin());
		rem1(*ms1.begin());
	}
}

void rem(ll x) {
	if (x <= 0) return;
	auto it = ms2.find(x);
	if (it != ms2.end())
		ms2.erase(it);
	else {
		rem1(x);
		if(ms1.size() < b && !ms2.empty()) {
			add1(*--ms2.end());
			ms2.erase(--ms2.end());
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	vector<ll> hp(n), dmg(n);
	for (int i = 0; i < n; ++i)
		cin >> hp[i] >> dmg[i];
	ll offset = 0;
	for (int i = 0; i < n; ++i) {
		offset += dmg[i];
		add(hp[i] - dmg[i]);
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		rem(hp[i] - dmg[i]);
		add(hp[i] * (1ll << a) - dmg[i]);
		res = max(res, offset + sum);
		rem(hp[i] * (1 << a) - dmg[i]);
		add(hp[i] - dmg[i]);
	}
	cout << res;
	return 0;
}