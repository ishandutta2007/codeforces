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
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector <int> operator +(vector <int> a, vector <int> b) {
	if (a.size() < b.size()) {
		a.swap(b);
	}

	for (int i = 0; i < (int)b.size(); i++) {
		a[i] += b[i];
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] >= 10) {
			if (i + 1 == (int)a.size()) {
				a.push_back(0);
			}

			a[i + 1]++;
			a[i] -= 10;
		}
	}

	return a;
}

vector <int> operator -(vector <int> a, vector <int> b) {
	for (int i = 0; i < (int)b.size(); i++) {
		a[i] -= b[i];
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] < 0) {
			a[i + 1]--;
			a[i] += 10;
		}
	}

	while (a.back() == 0) {
		a.pop_back();
	}

	return a;
}

vector <int> operator *(vector <int> a, int x) {
	for (int i = 0; i < (int)a.size(); i++) {
		a[i] *= x;
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] >= 10) {
			if (i + 1 == (int)a.size()) {
				a.push_back(0);
			}

			a[i + 1] += a[i] / 10;;
			a[i] %= 10;
		}
	}

	return a;
}

vector <int> operator /(vector <int> a, int x) {
	vector <int> ans;
	int cur = 0;

	for (int i = (int)a.size() - 1; i >= 0; i--) {
		cur *= 10;
		cur += a[i];
		if (!ans.empty() || (cur / x != 0)) {
			ans.push_back(cur / x);
		}

		cur %= x;
	}

	reverse(all(ans));
	return ans;
}

bool operator <(vector <int> a, vector <int> b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	for (int i = (int)a.size() - 1; i >= 0; i--) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}

	return false;
}

vector <int> build(ll a) {
	vector <int> g;

	while (a) {
		g.push_back(a % 10);
		a /= 10;
	}

	return g;
}

void write(vector <int> a) {
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		cout << a[i];
	}

	cout << '\n';
}

int mag = 50;

const int maxn = 210;

ll st[maxn];
ll res[maxn];

ll go(vector <int> a, bool in) {
	ll sum = 0;
	ll ans = 0;

	for (int i = (int)a.size() - 1; i >= 0; i--) {
		for (int c = 0; c < a[i]; c++) {
			ans += st[i] * (sum + c);
			ans += res[i];
		}

		sum += a[i];
	}

	return ans + (in ? sum : 0);
}

int main() {
	st[0] = 1;
	res[0] = 0;

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * 10;
		res[i] = res[i - 1] * 10;

		for (int j = 1; j < 10; j++) {
			res[i] += j * st[i - 1];
		}
	}

	ll a;

	cin >> a;

	if (a < 1700) {
		vector <int> f;

		while (a) {
			f.push_back((int)min(a, 9ll));
			a -= min(a, 9ll);
		}

		write(f);
		write(f);
		return 0;
	}

	while (true) {
		vector <int> l;

		for (int i = 0; i < mag; i++) {
			l.push_back(rand() % 9 + 1);
		}

		ll dx = mag;

		vector <int> lm = l;
		vector <int> rm = l + build(a / mag);

		vector <int> one;
		one.push_back(1);

		ll cur = go(lm, false);

		while (lm < rm) {
			vector <int> m = (lm + rm) / 2;

			ll now = go(m, true);

			if (now - cur < a) {
				lm = m + one;
			}
			else {
				rm = m;
			}
		}

		ll h = go(rm, true) - cur;

		if (h == a) {
			write(l);
			write(rm);
			break;
		}
	}
}