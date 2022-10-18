#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 6e5 + 42;

int par[maxn];
vector<int> comp[maxn], extra[maxn];

int color[maxn], inv[maxn], cnt[maxn], forced[maxn];
int total;

int get(int v) {
	return v == par[v] ? v : par[v] = get(par[v]);
}

int getb(int v) {
	return inv[v] ? comp[v].size() - cnt[v] : cnt[v];
}
int getw(int v) {
	return inv[v] ? cnt[v] : comp[v].size() - cnt[v];
}
int getc(int v) {
	return color[v] ^ inv[get(v)];
}

void uni(int a, int b) {
	int A = get(a);
	int B = get(b);
	if(comp[A].size() < comp[B].size()) {
		swap(A, B);
		swap(a, b);
	}
	if(A != B) {
		total -= getb(A) + getb(B);
		int ca = getc(a);
		int cb = getc(b);
		if(ca == cb) {
			int bA = getb(A);
			int wA = getw(A);
			int bB = getb(B);
			int wB = getw(B);
			if(!forced[A] && (bA - wA > bB - wB || forced[B])) {
				inv[A] ^= 1;
			} else {
				inv[B] ^= 1;
			}
		}
		par[B] = A;
		forced[A] |= forced[B];
		cnt[A] += (inv[B] == inv[A]) ? cnt[B] : comp[B].size() - cnt[B];
		for(auto it: comp[B]) {
			color[it] ^= inv[A] ^ inv[B];
			comp[A].push_back(it);
		}
		for(auto it: extra[B]) {
			color[it] ^= inv[A] ^ inv[B];
			extra[A].push_back(it);
		}
		total += getb(A);
	}
}

void force(int v, int c) {
	forced[get(v)] = 1;
	if(getc(v) != c) {
		v = get(v);
		total -= getb(v);
		inv[v] ^= 1;
		total += getb(v);
	}
}

void solve() {
	iota(par, par + maxn, 0);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		comp[i] = {i};
	}
	for(int i = k; i < maxn; i++) {
		extra[i] = {i};
	}
	string s;
	cin >> s;
	int sz = k;
	vector<int> sets[n];
	for(int i = 0; i < k; i++) {
		int c;
		cin >> c;
		for(int j = 0; j < c; j++) {
			int t;
			cin >> t;
			sets[t - 1].push_back(i);
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			if(sets[i].size() == 1) {
				force(sets[i][0], 1);
			} else {
				uni(sets[i][0], sets[i][1]);
			}
		} else {
			if(sets[i].size() == 1) {
				force(sets[i][0], 0);
			} else if(sets[i].size() == 2) {
				uni(sets[i][0], sz);
				uni(sets[i][1], sz);
				sz++;
			}
		}
		cout << total << "\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}