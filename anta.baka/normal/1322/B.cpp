#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <random>
#include <queue>
#include <cstring>

#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

const int N = 4e5 + 228;

int n;
int a[N];
ll cnt_bit[25];
int cnt[2];
int new_a[N];
vi z, o;

void upd(int bit, int x) {
	cnt_bit[bit] += x;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	z.reserve(n);
	o.reserve(n);
	for (int bit = 0; bit < 25; bit++) {
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++) {
			cnt[a[i] >> bit & 1]++;
		}
		cnt[1] += cnt[0];
		for (int i = n - 1; i >= 0; i--) {
			new_a[--cnt[a[i] >> bit & 1]] = a[i];
		}
		memcpy(a, new_a, sizeof(a));
		z.clear();
		o.clear();
		for (int i = 0; i < n; i++) {
			if (a[i] >> bit & 1) {
				o.pb(a[i] & ((1 << bit) - 1));
			}
			else {
				z.pb(a[i] & ((1 << bit) - 1));
			}
		}
		int pz = 0, po = 0;
		for(int i = sz(z) - 1; i >= 0; i--) {
			int x = z[i];
			while (pz < sz(z) && x + z[pz] < (1 << bit)) {
				pz++;
			}
			while (po < sz(o) && x + o[po] < (1 << bit)) {
				po++;
			}
			upd(bit, sz(z) - pz - (pz < sz(z) && z[pz] <= x));
			upd(bit, po);
		}
		pz = po = 0;
		for(int i = sz(o) - 1; i >= 0; i--) {
			int x = o[i];
			while (pz < sz(z) && x + z[pz] < (1 << bit)) {
				pz++;
			}
			while (po < sz(o) && x + o[po] < (1 << bit)) {
				po++;
			}
			upd(bit, pz);
			upd(bit, sz(o) - po - (po < sz(o) && o[po] <= x));
		}
	}
	int ans = 0;
	for (int i = 0; i < 25; i++) {
		if ((cnt_bit[i] >> 1) & 1) {
			ans ^= (1 << i);
		}
	}
	cout << ans;
}