#include<bits/stdc++.h>
using namespace std;

const int MAXX = 1000001;
const int N = 200005;
const int MOD = 1000000007;

struct Query {
	int l, r, id;

	bool operator <(const Query &y) const{
		return r < y.r;
	}
} que[N];

int minPrime[MAXX], n, pref[N];
vector<int> a[N];
unordered_map<int, int> ph, iph;
int bit[N];
int ipref[N], ans[N], last[MAXX];

int power(int x, int y) {
	if (y == 0) return 1;
	int temp = power(x, y / 2);
	temp = 1LL * temp * temp % MOD;
	if (y % 2) temp = 1LL * temp * x % MOD;
	return temp;
}

int inv(int x) {
	return power(x, MOD - 2);
}

void update(int k, int val) {
	for (int i = k; i < N; i += (i & (-i))) {
		bit[i] = 1LL * bit[i] * val % MOD;
	}
}

int get(int k) {
	int res = 1;
	for (int i = k; i > 0; i -= (i & (-i))) {
		res = 1LL * res * bit[i] % MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i * i < MAXX; i++) {
		if (minPrime[i] == 0) {
			for (int j = i * i ; j < MAXX; j += i) {
				if (minPrime[j] == 0) {
					minPrime[j] = i;
				}
			}
		}
	}
	for (int i = 2; i < MAXX; i++) {
		if (minPrime[i] == 0) minPrime[i] = i;
	}
	for (int i = 1; i < MAXX; i++) {
		if (minPrime[i] == i) {
			ph[i] = 1LL * (i - 1) * inv(i) % MOD;
			iph[i] = inv(ph[i]);
		}
	}
	cin >> n;
	pref[0] = 1;
	ipref[0] = inv(pref[0]);
	for (int i = 1; i <= n; i++) {
		int u; cin >> u;
		//cout << " 1" << endl;
		pref[i] = (1LL * pref[i - 1] * u) % MOD;
		ipref[i] = inv(pref[i]);
		while (u != 1) {
			int t = minPrime[u];
			while (u % t == 0) {
				u /= t;
			}
			a[i].push_back(t);
		}
	}
	memset(last, -1, sizeof(last));
	for (int i = 0; i < N; i++) bit[i] = 1;
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> que[i].l >> que[i].r;
		que[i].id = i;
	}
	sort(que + 1, que + q + 1);
	int cur = 0;
	for (int i = 1; i <= q; i++) {
		while (cur < que[i].r) {
			cur++;
			for (auto p : a[cur]) {
				if (last[p] != -1) {
					update(last[p], iph[p]);
				}
				update(cur, ph[p]);
				last[p] = cur;
			}
		}
		int l = que[i].l, r = que[i].r;
		int res = 1LL * get(r) * inv(get(l - 1)) % MOD;
		res = 1LL * res * pref[r] % MOD * ipref[l - 1] % MOD;
		ans[que[i].id] = res;
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}