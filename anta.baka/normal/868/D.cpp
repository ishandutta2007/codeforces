#include <bits/stdc++.h>

using namespace std;

const int K = 19;

int n, q;
string pref[200], suff[200];
bitset<(1 << K)> is[200][K];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int sz = s.size();
		for(int k = 1; k <= K; k++) {
			int num = 0;
			for(int j = 0; j < sz; j++) {
				num = num + num + s[j] - '0';
				if(j + 1 >= k) {
					is[i][k - 1].set(num);
					num -= (s[j - k + 1] - '0') * (1 << (k - 1));
				}
			}
		}
		pref[i] = s.substr(0, K);
		suff[i] = s.substr(max(0, sz - K));
	}
	cin >> q;
	for(int id = n; id < n + q; id++) {
		int a, b; cin >> a >> b; --a; --b;
		pref[id] = pref[a] + pref[b];
		if(pref[id].size() > K)
			pref[id].resize(K);
		suff[id] = suff[a] + suff[b];
		if(suff[id].size() > K) {
			reverse(suff[id].begin(), suff[id].end());
			suff[id].resize(K);
			reverse(suff[id].begin(), suff[id].end());
		}
		string s = suff[a] + pref[b];
		int sz = s.size();
		int ret = 0;
		for(int k = 1; k <= K; k++) {
			is[id][k - 1] = is[a][k - 1] | is[b][k - 1];
			int num = 0;
			for(int j = 0; j < sz; j++) {
				num = num + num + s[j] - '0';
				if(j + 1 >= k) {
					is[id][k - 1].set(num);
					num -= (s[j - k + 1] - '0') * (1 << (k - 1));
				}
			}
			if(is[id][k - 1].count() == (1 << k))
				ret = k;
		}
		cout << ret << '\n';
	}
}