#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b) {
	while (b > 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (y % x) return cout << 0, 0;
	ll k = y / x;
	vector<ll> b, c;
	for (int i = 0; i < n; ++i)
		if (a[i] % x == 0)
			b.push_back(gcd(a[i] / x, k));
	for (int i = 0; i < n; ++i)
		if (y % a[i] == 0)
			c.push_back(gcd(y / a[i], k));
	unordered_map<ll, int> d, e;
	for (int i = 0; i < b.size(); ++i)
		d[b[i]]++;
	for (int i = 0; i < c.size(); ++i)
		e[c[i]]++;
	ll ans = 0ll;
	if ((ll)d.size() * (ll)e.size() <= 10'000'000) {
		for (auto i = d.begin(); i != d.end(); ++i)
			for (auto j = e.begin(); j != e.end(); ++j)
				if (gcd(i->first, j->first) == 1)
					ans += i->second * 1ll * j->second;
		cout << ans;
	}
	else {
		vector<ll> pr;
		ll t = k;
		for (int i = 2; i * i <= t; ++i) {
			if (t % i == 0) {
				pr.push_back(i);
				while (t % i == 0) t /= i;
			}
		}
		if (t > 1) pr.push_back(t);
		int cnt = (int)pr.size();
		vector<int> st(cnt + 1, 1);
		for (int i = 1; i <= cnt; ++i)
			st[i] = st[i - 1] << 1;
		vector<int> cl(st[cnt]), allcl(st[cnt]);
		for (int i = 0; i < b.size(); ++i) {
			int hash = 0;
			for (int j = 0; j < cnt; ++j) {
				if (b[i] % pr[j] == 0)
					hash += st[j];
			}
			cl[hash]++;
		}
		for (int i = 0; i < st[cnt]; ++i) {
			int al = 0;
			for (int j = 0; j < cnt; ++j)
				if (i & st[j]) al++;
			for (int j = 0; j < st[al]; ++j) {
				int l = 0, hash = 0;
				for (int r = 0; r < cnt; ++r) {
					if (i & st[r]) {
						if (j & st[l])
							hash += st[r];
						l++;
					}
				}
				allcl[i] += cl[hash];
			}
		}
		ll ans = 0;
		for (int i = 0; i < c.size(); ++i) {
			int hash = 0;
			for (int j = 0; j < cnt; ++j) {
				if (c[i] % pr[j] == 0)
					hash += st[j];
			}
			ans += allcl[st[cnt] - 1 - hash];
		}
		cout << ans;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}