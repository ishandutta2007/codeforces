#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 4e5 + 10;
const int mod = 998244353;

int fen[maxn];
int x[maxn], y[maxn], s[maxn];
vector<int> cmp;

int get(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret = (ret + fen[idx]) % mod;
	return ret;
}

void add(int idx, int val) {
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] = (fen[idx] + val) % mod;
}

void addAfterCompress(int x, int val) {
	int idx = lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin() + 1;
	add(idx, val);
}

int getAfterCompress(int x) {
	int idx = lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin() + 1;
	return get(idx);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> s[i];
		cmp.push_back(x[i]);
		cmp.push_back(y[i]);
	}
	int answer = (x[n - 1] + 1) % mod;
	sort(cmp.begin(), cmp.end());
	for (int i = n - 1; i >= 0; i--) { 
		int A = getAfterCompress(x[i]);
		int B = (s[i] + 1LL * A % mod) % mod;
		answer = (answer + 1LL * B * (x[i] - y[i]) % mod) % mod;
		addAfterCompress(y[i], B);
	}
	cout << answer << endl;
}