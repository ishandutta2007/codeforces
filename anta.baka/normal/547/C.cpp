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

const int A = (int)5e5 + 1;

int n, q;
vi a;
vi del[A];
int lp[A];
int cnt[A];
bool has[A];
ll ans;
int cn;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	memset(lp, -1, sizeof(lp));
	for (int i = 2; i < A; i++) {
		for (int j = i; j < A; j += i) {
			del[j].pb(i);
			if (lp[j] == -1) {
				lp[j] = i;
			}
		}
	}
	cin >> n >> q;
	a.resize(n);
	for (int& x : a) cin >> x;
	while (q--) {
		int i; cin >> i; --i;
		int x = a[i];
		vi pr;
		while (x > 1) {
			int p = lp[x];
			pr.pb(p);
			while (x % p == 0) x /= p;
		}
		if (has[i]) {
			has[i] = false;
			for (int d : del[a[i]]) cnt[d]--;
			cn--;
			int add = 0;
			for (int m = 0; m < (1 << sz(pr)); m++) {
				int k = -1;
				int mul = 1;
				for (int i = 0; i < sz(pr); i++) {
					if ((m >> i) & 1) {
						mul *= pr[i];
						k *= -1;
					}
				}
				if (mul > 1) add += k * cnt[mul];
			}
			ans -= add;
		}
		else {
			int add = 0;
			for (int m = 0; m < (1 << sz(pr)); m++) {
				int k = -1;
				int mul = 1;
				for (int i = 0; i < sz(pr); i++) {
					if ((m >> i) & 1) {
						mul *= pr[i];
						k *= -1;
					}
				}
				if (mul > 1) add += k * cnt[mul];
			}
			has[i] = true;
			ans += add;
			for (int d : del[a[i]]) cnt[d]++;
			cn++;
		}
		cout << 1LL * cn * (cn - 1) / 2 - ans << '\n';
	}
}