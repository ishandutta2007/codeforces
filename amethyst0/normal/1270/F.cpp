//#pragma comment(linker, "/STACK:1000000000")
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, sq = 250;
char s[maxn];

int stup(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i; j < n; j++) {
			cnt += s[j] - '0';

			if (cnt != 0 && (j - i + 1) % cnt == 0) {
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	scanf("%s", s);
	srand(11);

	for (int i = 0; i < 500; i++) {
		//s[i] = '0' + rand() % 2;
	}

	//cout << s << endl;

	vector <pii> v;

	int n = strlen(s);

	//cout << stup(n) << endl;

	int x = 0, y = 0;

	v.push_back(mp(x, y));

	for (int i = 0; i < n; i++) {
		y++;
		x += s[i] - '0';
		v.push_back(mp(x, y));
	}

	ll ans = 0;

	for (int k = 1; k < sq; k++) {
		vector <ll> g;

		for (pii f : v) {
			g.push_back(f.second - (ll)k * f.first);
		}

		sort(g.begin(), g.end());
		int l = 0;

		while (l < (int)g.size()) {
			int r = l;

			while (r < (int)g.size() && g[l] == g[r]) {
				r++;
			}

			ans += (ll)(r - l) * (r - l - 1) / 2;
			l = r;
		}
	}

	vector <int> ps;

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ps.push_back(i);
		}
	}

	for (int i = 0; i < (int)ps.size(); i++) {
		for (int j = i; j < (int)ps.size(); j++) {
			int len = (j - i + 1) * sq;
			if (len > n) {
				break;
			}

			int x = ps[i];

			if (i != 0) {
				x -= ps[i - 1];
				x--;
			}

			int y = n - 1 - ps[j];

			if (j != (int)ps.size() - 1) {
				y = ps[j + 1] - ps[j] - 1;
			}

			int pre = ans;

			for (int k = 0; k <= x; k++) {
				int cur = k + ps[j] - ps[i] + 1;
				int yy = y;
				int nx = (cur + j - i) / (j - i + 1) * (j - i + 1);
				yy -= nx - cur;
				cur = nx;
				yy = yy - max(0, len - cur);
				if (yy >= 0) {
					ans += yy / (j - i + 1) + 1;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}