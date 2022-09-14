#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

string s;

vector <int> z[3];
ll ch[3];
int n;

void solve(ll, int);

void gen(ll x, int y, int cnt) {
	if (x == 0) {
		solve(y, cnt + 1);
		return;
	}

	if (x >= 10) {
		z[cnt].push_back(2);
		gen(x / 100,y + x % 100, cnt);
		z[cnt].pop_back();
	}

	z[cnt].push_back(1);
	gen(x / 10, y + x % 10, cnt);
	z[cnt].pop_back();
}

void solve(ll x, int cnt) {
	if (cnt == 3) {
		if (x >= 10) {
			return;
		}

		int pos = 0;

		for (int i = (int)z[0].size() - 1; i >= 0; i--) {
			if (z[0][i] == 1) {
				printf("%c", s[pos++]);
			} else {
				printf("%c%c", s[pos], s[pos + 1]);
				pos += 2;
			}

			if (i != 0) {
				printf("+");
			}
		}

		printf("\n");

		for (int i = 1; i < 3; i++) {
			string res = "";

			for (int j = 0; j < (int)z[i].size(); j++) {
				if (z[i][j] == 1) {
					res += '0' + ch[i] % 10;
					ch[i] /= 10;
				} else {
					res += '0' + ch[i] % 10;
					ch[i] /= 10;
					res += '0' + ch[i] % 10;
					ch[i] /= 10;
				}

				if (j != (int)z[i].size() - 1) {
					res += '+';
				}
			}

			reverse(res.begin(), res.end());

			cout << res << endl;
		}

		exit(0);
	} else {
		ch[cnt] = x;
		z[cnt].clear();
		gen(x, 0, cnt);
	}
}

int main() {
	cin >> n;

	cin >> s;

	if (n <= 15) {
		ll x = 0;

		for (int i = 0; i < n; i++) {
			x *= 10;
			x += s[i] - '0';
		}

		solve(x, 0);
	} else {
		while (true) {
			ll x = 0;

			z[0].clear();

			for (int i = 0; i < n ; ) {
				int d = rand() % 2 + 1;

				if (i + d > n) {
					d = 1;
				}

				z[0].push_back(d);

				if (d == 1) {
					x += s[i] - '0';
					i++;
				} else {
					x += 10 * (s[i] - '0');
					i++;
					x += s[i] - '0';
					i++;
				}
			}

			reverse(z[0].begin(), z[0].end());

			solve(x, 1);
		}
	}

	return 0;
}