//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

bool cmp(pll a, pll b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}

	return a.second > b.second;
}

const int maxn = (int)1e7;

struct vt {
	int ed[2];
	bool term;

	vt() {
		ed[0] = ed[1] = -1;
		term = false;
	}
};

vt mas[maxn];
int posit = 0;

int my_new() {
	if (posit == maxn) {
		throw 1;
	}
	return posit++;
}

void add(int t, ll x, int b, int mb) {
	if (b == mb) {
		//cout << "!" << x << ' ' << b << endl;
		mas[t].term = true;
		return;
	}

	int c = (x >> b) & 1;

	if (mas[t].ed[c] == -1) {
		mas[t].ed[c] = my_new();
	}

	add(mas[t].ed[c], x, b - 1, mb);
}

void make(vector <pll> &a) {
	sort(a.begin(), a.end(), cmp);

	ll rm = -1;

	vector <pll> res;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].second <= rm) {
			continue;
		}
		else {
			rm = a[i].second;
			res.push_back(a[i]);
		}
	}

	a = res;
}

int t;

void calc(ll la, ll ra, ll lb, ll rb) {
	add(t, la ^ lb, 59, -1);
	add(t, ra ^ rb, 59, -1);
	add(t, la ^ rb, 59, -1);
	add(t, ra ^ lb, 59, -1);

	for (int b = 59; b >= 0; b--) {
		ll lx = (la >> b);
		ll ly = (lb >> b);
		ll rx = (ra >> b);
		ll ry = (rb >> b);

		if (lx != rx && (lx + 1) != rx) {
			if ((lx & 1) == 0) {
				add(t, ((lx + 1) ^ ly) << b, 59, b - 1);
				add(t, ((lx + 1) ^ ry) << b, 59, b - 1);
			}

			if ((rx & 1) == 1) {
				add(t, ((rx - 1) ^ ly) << b, 59, b - 1);
				add(t, ((rx - 1) ^ ry) << b, 59, b - 1);
			}
		}
		
		if (ly != ry && (ly + 1) != ry) {
			if ((ly & 1) == 0) {
				add(t, (lx ^ (ly + 1)) << b, 59, b - 1);
				add(t, (rx ^ (ly + 1)) << b, 59, b - 1);
			}

			if (ry & 1) {
				add(t, (lx ^ (ry - 1)) << b, 59, b - 1);
				add(t, (rx ^ (ry - 1)) << b, 59, b - 1);
			}
		}

		if (lx != rx && (lx + 1) != rx && ly != ry && (ly + 1) != ry) {
			if ((lx & 1) == 0 && (ly & 1) == 0) {
				add(t, ((lx + 1) ^ (ly + 1)) << b, 59, b - 1);
			}

			if ((lx & 1) == 0 && (ry & 1) == 1) {
				add(t, ((lx + 1) ^ (ry - 1)) << b, 59, b - 1);
			}

			if ((rx & 1) == 1) {
				if ((ly & 1) == 0) {
					add(t, ((rx - 1) ^ (ly + 1)) << b, 59, b - 1);
				}

				if ((ry & 1) == 1) {
					add(t, ((rx - 1) ^ (ry - 1)) << b, 59, b - 1);
				}
			}
		}
	}
}

const int mod = 998244353;

const int maxlog = 135;

int st[maxlog];

int build(int t, int b, ll x) {
	if (mas[t].term) {
		int y = x % mod;
		y = (ll)y * st[b + 1] % mod;
		int ans = (ll)y * st[b + 1] % mod;
		ans += (ll)st[b] * (st[b + 1] - 1) % mod;
		ans %= mod;
		if (ans < 0) {
			ans += mod;
		}

		return ans;
	}

	int ans = 0;

	if (mas[t].ed[0] != -1) {
		ans = build(mas[t].ed[0], b - 1, x << 1);
	}

	if (mas[t].ed[1] != -1) {
		ans += build(mas[t].ed[1], b - 1, (x << 1) + 1);
		if (ans >= mod) {
			ans -= mod;
		}
	}

	return ans;
}

signed main() {
	t = my_new();

	int n;
	cin >> n;

	vector <pll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	int m;

	cin >> m;

	vector <pll> b(m);

	for (int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
	}

	make(a);
	make(b);

	n = (int)a.size();
	m = (int)b.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			calc(a[i].first, a[i].second, b[j].first, b[j].second);
		}
	}

	st[0] = 1;

	for (int i = 1; i < maxlog; i++) {
		st[i] = st[i - 1] * 2 % mod;
	}

	int ans = build(t, 59, 0);

	cout << ans << endl;

	//system("pause");
}