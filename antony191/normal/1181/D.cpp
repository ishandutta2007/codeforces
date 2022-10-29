#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
#define int long long
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
int t[2000000];
void build(vector<int>&a, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(a, v + v, tl, tm);
		build(a, v + v + 1, tm + 1, tr);
		t[v] = t[v + v] + t[v + v + 1];
	}	
}
void upd(int v, int tl, int tr, int pos, int col) {
	if (tl == tr) {
		t[v] = col;
	}
	else {
		int tm = (tl + tr) / 2;
		if (tm >= pos) {
			upd(v + v, tl, tm, pos, col);
		}
		else {
			upd(v + v + 1, tm + 1, tr, pos, col);
		}
		t[v] = t[v + v] + t[v + v + 1];
	}
}
int sum(int v, int tl, int tr, int zz) {
	if (tl == tr) return tl;
	int m = (tl + tr) >> 1;
	if (t[v + v] >= zz) return sum(v + v, tl, m, zz);
	return sum(v + v + 1, m + 1, tr, zz - t[v + v]);
}
signed main() {
	int k, n, q;
	cin >> k >> n >> q;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		a[x].first++;
	}
	for (int i = 0; i < n; i++) {
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int>pref(n);
	int summ = a[0].first;
	for (int i = 1; i < n; i++) {
		pref[i] = i * a[i].first - summ;
		summ += a[i].first;
	}
	vector<pair<ll, int>>z(q);
	vector<int>ans(q);
	for (int i = 0; i < q; i++) {
		cin >> z[i].first;
		z[i].first -= k;
		z[i].second = i;
	}
	sort(z.begin(), z.end());
	int col = 0;
	vector<int>b(n);

	for (int w = 0; w < q; w++) {
		/*int l = -1;
		int r = n;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (pref[m] >= z[w].first) {
				r = m;
			}
			else {
				l = m;
			}
		}*/
		int r = lower_bound(pref.begin(), pref.end(), z[w].first) - pref.begin();
		if (r > n) r = n;
		for (int i = col; i < r; i++) {
			b[a[i].second] = 1;
			upd(1, 0, n - 1, a[i].second, 1);
		}
		col = r;
		ll zz = (z[w].first - (ll)pref[r - 1]) % r;
		if (zz == 0) {
			zz = r;
		}
		ans[w] = sum(1, 0, n - 1, zz);
	}
	vector<int>ans2(q);
	for (int w = 0; w < q; w++) {
		ans2[z[w].second] = ans[w];
	}
	for (int i = 0; i < q; i++) {
		cout << ans2[i] + 1 << '\n';
	}
	return 0;
}