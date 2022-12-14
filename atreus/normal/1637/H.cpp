#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 10;
const ll mod = 998244353;

int p[maxn], s[maxn], d[maxn], c[maxn];
int fen[maxn];

void add(int idx, int val) {
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += val;
}

int get(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

// Inversion = inv - Sum d[i] + seqInv - (C(|seq|, 2) - seqInv)

// inv - sum d[i] + 2 seqInv - C(seq, 2);


void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = n; i >= 1; i--) {
		s[i] = get(p[i]);
		add(p[i], 1);
		d[i] = - (p[i] - 1 - s[i]) + (i - p[i] + s[i]);
		c[i] = d[i] - 2 * s[i];
	}
	ll inv = 0;
	for (int i = 1; i <= n; i++)
		inv += s[i];
	sort(c + 1, c + n + 1, greater<int>());
	cout << inv << " ";
	for (int i = 1; i <= n; i++) {
		inv -= c[i];
		cout << inv - 1LL * i * (i - 1) / 2 << " \n"[i == n];
	}
	for (int i = 1; i <= n; i++)
		add(i, -1);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}