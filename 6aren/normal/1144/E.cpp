#include<bits/stdc++.h>

using namespace std;

int n;
string s, t;
vector<int> v[2], res;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> s >> t;
	for (int i = n - 1; i >= 0; i--) {
		v[0].push_back(s[i] - 'a');
		v[1].push_back(t[i] - 'a');
	}
	v[0].push_back(0);
	v[1].push_back(0);
	int mmr = 0;
	for (int i = 0; i <= n; i++) {
		int u = v[0][i] + v[1][i] + mmr;
		mmr = u / 26;
		res.push_back(u % 26);
	}
	if (res[n]) mmr = 26;
	else mmr = 0;
	for (int i = n - 1; i >= 0; i--) {
		res[i] += mmr;
		if (res[i] % 2 == 0) {
			res[i] = res[i] / 2;
			mmr = 0;
		} else {
			res[i] = (res[i] - 1) / 2;
			mmr = 26;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << (char) ('a' + res[i]);
	}
	return 0;
}