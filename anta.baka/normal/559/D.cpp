#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 100001;

int n;
int x[2 * N];
int y[2 * N];
int g[2 * N];
ll s;
ld ans;
ld pw[N];

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

ll crs(pii a, pii b) {
	return 1LL * a.first * b.second - 1LL * a.second * b.first;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	pw[0] = (ld)1.0;
	for (int i = 1; i < N; i++) {
		pw[i] = (ld)0.5 * pw[i - 1];
	}
	cin >> n;
	ld den = 1 + n + 1LL * n * (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		den *= (ld)0.5;
	}
	den = (ld)1.0 - den;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i + n] = x[i];
		y[i + n] = y[i];
	}
	for (int i = 0; i < n; i++) {
		g[i] = gcd(abs(x[i] - x[i + 1]), abs(y[i] - y[i + 1]));
		g[i + n] = g[i];
		s += crs({ x[i], y[i] }, { x[i + 1], y[i + 1] });
	}
	if (s < 0) {
		s = -s;
	}
	for (int i = 0; i < n; i++) {
		s -= g[i];
	}
	s += 2;
	s >>= 1;
	ans = s;
	int D = min(n - 2, 60);
	for (int i = 0; i < n; i++) {
		ll ss = 0;
		ll gg = 0;
		for (int d = 1; d <= D; d++) {
			int j = i + d;
			ss += crs({ x[j - 1], y[j - 1], }, { x[j], y[j] });
			gg += g[j - 1];
			if (d > 1) {
				ll curs = ss;
				curs += crs({ x[j], y[j] }, { x[i], y[i] });
				if (curs < 0) {
					curs = -curs;
				}
				//cout << "? " << curs << endl;
				ll curg = gg;
				int ons = gcd(abs(x[j] - x[i]), abs(y[j] - y[i]));
				curg += ons;
				curs -= curg;
				curs += 2;
				curs >>= 1;
				curs += ons - 1;
				ld p = (pw[d + 1] - pw[n]) / den;
				//cout << i << ' ' << j << ' ' << curs << ' ' << p << endl;
				ans -= p * curs;
			}
		}
	}
	cout << setprecision(10) << ans;
}