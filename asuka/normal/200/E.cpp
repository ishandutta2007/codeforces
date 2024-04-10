#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int n, s, c3, c4, c5;

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &s);

	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		(x == 3 ? c3 : x == 4 ? c4 : c5)++;
	}

	int a3 = -1, a4 = -1, a5 = -1, ans = inf, g = __gcd(c3, c5);
	auto check = [&](int k3, int k4, int k5) {
		if (0 <= k3 && k3 <= k4 && k4 <= k5 && c3 * k3 + c4 * k4 + c5 * k5 == s) {
			int nans = abs(k3 * c3 - k4 * c4) + abs(k4 * c4 - k5 * c5);

			if (nans < ans) {
				ans = nans;
				a3 = k3;
				a4 = k4;
				a5 = k5;
			}
		}
	};

	for (int k4 = 0; k4 * c4 <= s; k4++) {
		rep(_, 0, n) {
			int K3 = (k4 * c4 / c3) + _;

			if ((s - c3 * K3 - c4 * k4) % c5 == 0) {
				rep(__, -500, 500) {
					int k3 = K3 + __ * (c5 / g), k5 = (s - k4 * c4 - k3 * c3) / c5;
					check(k3, k4, k5);
				}

				break;
			}
		}

		rep(_, 0, n) {
			int K5 = (c4 * k4 / c5) + _;

			if ((s - c5 * K5 - c4 * k4) % c3 == 0) {
				rep(__, -500, 500) {
					int k5 = K5 + __ * (c3 / g), k3 = (s - k4 * c4 - k5 * c5) / c3;
					check(k3, k4, k5);
				}

				break;
			}

		}

	}

	if (a3 == -1) printf("-1\n");
	else printf("%d %d %d\n", a3, a4, a5);

	return 0;
}