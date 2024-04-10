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
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define uint unsigned int
#define pb push_back
#define sz(a) (int)(a.size())

using namespace std;

struct vt {
	ld x, y;

	vt(): x(0), y(0) {

	}

	vt(ld x, ld y): x(x), y(y) {

	}
};

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;

	return a;
}

vt operator *(vt a, vt b) {
	return vt(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

int rev(int x, int st) {
	int y = 0;

	for (int i = 0; i < st; i++) {
		y <<= 1;
		y += x & 1;
		x >>= 1;
	}

	return y;
}

const ld pi = acos(-1.0);

void fft(vector <vt> &v, int st, bool fl) {
	int n = (1 << st);

	for (int i = 0; i < n; i++) {
		int x = rev(i, st);

		if (x < i) {
			swap(v[i], v[x]);
		}
	}

	for (int len = 1; len <= n; len <<= 1) {
		ld ang = 2 * pi / len * (fl ? -1 : 1);
		vt wlen = vt(cos(ang), sin(ang));

		for (int i = 0; i < n; i += len) {
			vt w = vt(1, 0);
			for (int j = i; j < i + len / 2; j++) {
				vt a = v[j];
				vt b = v[j + len / 2] * w;

				v[j] = a + b;
				v[j + len / 2] = a - b;

				w = w * wlen;
			}
		}
	}

	if (fl) {
		for (int i = 0; i < n; i++) {
			v[i].x /= n;
			v[i].y /= n;
		}
	}
}

vector <int> operator *(vector <int> a, vector <int> b) {
	vector <vt> c, d;

	int st = 0;

	while ((1 << st) < (int)max(a.size(), b.size())) {
		st++;
	}

	st++;

	c.resize(1 << st);
	d.resize(1 << st);

	for (int i = 0; i < (int)a.size(); i++) {
		c[i].x = a[i];
	}

	for (int i = 0; i < (int)b.size(); i++) {
		d[i].x = b[i];
	}

	fft(c, st, false);
	fft(d, st, false);

	for (int i = 0; i < (1 << st); i++) {
		c[i] = c[i] * d[i];
	}

	fft(c, st, true);

	a.resize(1 << st);

	for (int i = 0; i < (1 << st); i++) {
		a[i] = (int)(c[i].x + 0.5);
	}

	return a;
}

const int maxn = (int)5e5 + 10;
char s[maxn];
bool st[maxn];
vector <int> pr[maxn];

int main() {
	for (int i = 2; i < maxn; i++) {
		if (pr[i].empty()) {
			pr[i].push_back(i);

			for (int j = 2; i * j < maxn; j++) {
				pr[i * j].push_back(i);
			}
		}
	}

	int t;

	cin >> t;

	while (t--) {
		int n;

		scanf("%d", &n);
		scanf("%s", s);

		vector <int> a(n + 1, 0), b(n + 1, 0);

		for (int i = 0; i < n; i++) {
			st[i] = false;
			if (s[i] == 'V') {
				a[i] = 1;
			} else if (s[i] == 'K') {
				b[n - i] = 1;
			}
		}

		st[n] = false;

		a = a * b;

		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i] > 0) {
				int pos = i;

				if (pos > n) {
					pos -= n;
				} else {
					pos -= n;
					pos = abs(pos);
				}

				st[pos] = true;
			}
		}

		vector <int> ans;

		for (int i = n; i > 0; i--) {
			if (!st[i]) {
				ans.push_back(i);
			} else {
				//cout << i << endl;
				for (int j = 0; j < (int)pr[i].size(); j++) {
					st[i / pr[i][j]] = true;
				}
			}
		}

		printf("%d\n", (int)ans.size());

		while (!ans.empty()) {
			printf("%d ", ans.back());
			ans.pop_back();
		}

		printf("\n");
	}

	return 0;
}