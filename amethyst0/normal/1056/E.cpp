#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
char s[maxn], t[maxn];

int p = (int)1e9 + 7, q = 998244353;

pii operator +(pii a, pii b) {
	a.first += b.first;
	a.second += b.second;

	if (a.first >= p) {
		a.first -= p;
	}

	if (a.second >= q) {
		a.second -= q;
	}

	return a;
}

pii operator -(pii a, pii b) {
	a.first -= b.first;
	a.second -= b.second;

	if (a.first < 0) {
		a.first += p;
	}

	if (a.second < 0) {
		a.second += q;
	}

	return a;
}

pii operator *(pii a, pii b) {
	a.first = (ll)a.first * b.first % p;
	a.second = (ll)a.second * b.second % q;

	return a;
}

pii st[maxn];

pii hsh[maxn];

pii get_hsh(int l, int r) {
	if (l == 0) {
		return hsh[r];
	}
	else {
		return hsh[r] - hsh[l - 1] * st[r - l + 1];
	}
}

int z[maxn];

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	for (int i = (int)1e9; i >= 0; i--) {
		if (prime(i)) {
			p = i;
			break;
		}
	}

	for (int i = (int)8e5; i >= 0; i--) {
		if (prime(i)) {
			q = i;
			break;
		}
	}

	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * mp(1234567, 1234567);
	}

	scanf("%s %s", s, t);

	int n = strlen(s);
	int m = strlen(t);

	pii cur = mp(0, 0);

	for (int i = 0; i < m; i++) {
		cur = cur * st[1];
		cur = cur + mp(t[i] - 'a' + 1, t[i] - 'a' + 1);
		hsh[i] = cur;
	}

	int now = 0;

	vector <int> zer, one;

	for (int i = 0; i < n; i++) {
		z[i] = now;
		if (s[i] == '0') {
			now++;
			zer.push_back(i);
		}
		else {
			one.push_back(i);
		}
	}

	if (zer.empty() || one.empty()) {
		throw 1;
	}

	int ans = 0;

	for (int i = 1; i <= m; i++) {
		if ((ll)i * (int)zer.size() >= m) {
			break;
		}

		int j = m - i * (int)zer.size();

		if (j % (int)one.size() != 0) {
			continue;
		}

		j /= (int)one.size();

		int firs = -1;

		bool fl = true;

		for (int p = 0; p < (int)zer.size(); p++) {
			int pos = zer[p];
			int ps = z[pos] * i + (pos - z[pos]) * j;
			if (p == 0) {
				firs = ps;
			}
			else {
				if (get_hsh(firs, firs + i - 1) != get_hsh(ps, ps + i - 1)) {
					fl = false;
					break;
				}
			}
		}

		if (!fl) {
			continue;
		}

		int firt = -1;

		for (int p = 0; p < (int)one.size(); p++) {
			int pos = one[p];
			int ps = z[pos] * i + (pos - z[pos]) * j;
			if (p == 0) {
				firt = ps;
			}
			else {
				if (get_hsh(firt, firt + j - 1) != get_hsh(ps, ps + j - 1)) {
					fl = false;
					break;
				}
			}
		}

		if (!fl) {
			continue;
		}

		if (i == j) {
			if (get_hsh(firs, firs + i - 1) == get_hsh(firt, firt + j - 1)) {
				fl = false;
			}
		}

		if (fl) {
			ans++;
		}
	}

	cout << ans << endl;

	//system("pause");
}