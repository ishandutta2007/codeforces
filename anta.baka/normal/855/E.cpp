#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull dp[11][60][1024][10], sum[11][60][1024]; //    _

void pre() {
	for(int b = 2; b < 11; b++) {
		for(int dg = 0; dg < b; dg++) {
			dp[b][1][1 << dg][dg] = 1;
			sum[b][1][1 << dg] = 1;
		}
		ull lo = 1;
		for(int l = 2; ; l++) {
			lo = lo * b;
			if(lo > 1e18) break;
			for(int dg = 0; dg < b; dg++)
				for(int m = 0; m < (1 << b); m++) {
					dp[b][l][m][dg] += sum[b][l - 1][m ^ (1 << dg)];
					sum[b][l][m] += dp[b][l][m][dg];
				}
		}
	}
}

void base(ull n, int b, vector<int> &v) {
	while(n) v.push_back(n % b), n /= b;
	reverse(v.begin(), v.end());
}

ull get(ull n, int b) {
	if(!n) return 0;
	ull ret = 0;
	vector<int> v;
	base(n, b, v);
	for(int l = 2; l < v.size(); l += 2)
		for(int dg = 1; dg < b; dg++)
			ret += dp[b][l][0][dg];
	if(v.size() & 1) return ret;
	int m = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int x = i ? 0 : 1; x < v[i]; x++)
			ret += dp[b][v.size() - i][m][x];
		m ^= (1 << v[i]);
	}
	vector<int> c(b, 0);
	for(int x : v) c[x]++;
	for(int x = 0; x < b; x++)
		if(c[x] & 1)
			return ret;
	return ret + 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	pre();
	int q; cin >> q;
	while(q--) {
		int b; ull l, r;
		cin >> b >> l >> r;
		cout << get(r, b) - get(l - 1, b) << '\n';
	}
}