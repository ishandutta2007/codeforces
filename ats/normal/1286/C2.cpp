#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
vector<pair<pair<int, int>, int> > vp;
string res;
string X;
void ask(int L, int R) {
	if(L > R)return;
	cout << "? " << L + 1 << " " << R + 1 << "\n";
	cout << flush;
	int len = R - L + 1;
	vector<vector<int> > num(len + 1, vector<int>(26, 0));
	int ll = L;
	int rr = L;
	for (int i = 0; i < (len * (len + 1) / 2); i++) {
		string s;
		cin >> s;
		//s = X.substr(ll, rr - ll + 1);
		//cerr << s << endl;
		for (int j = 0; j < s.size(); j++) {
			num[s.size()][s[j] - 'a']++;
		}
		rr++;
		if (rr == R + 1) {
			ll++;
			rr = ll;
		}
	}
	vector<int> r(26, 0);
	for (int i = 0; i < (len + 1) / 2; i++) {
		vector<int> X;
		for (int j = 0; j < 26; j++) {
			for (int k = 0;
				 k < num[len][j] - (num[len - i - 1][j] - num[len - i][j]) - r[j];
				 k++) {
				X.push_back(j);
			}
		}
		if (L + i < R - i) {
			//cerr << X.size() << endl;
			vp.emplace_back(make_pair(L + i, R - i), X[0] + X[1]);
		} else {
			res[L + i] = X[0] + 'a';
		}
		for (int j : X) {
			r[j]++;
		}
	}
}
signed main() {
	int N;
	cin >> N;
	//cin >> X;
	res.resize(N, '.');
	int s1 = N / 3;
	ask(0, s1 * 2);
	ask(s1, N - 1);
	ask(s1 + 1, N - 1);
	for (int t = 0; t < N + 5; t++) {
		for (int i = 0; i < vp.size(); i++) {
			if (res[vp[i].first.first] == '.' && res[vp[i].first.second] != '.') {
				res[vp[i].first.first] =
					vp[i].second - (res[vp[i].first.second] - 'a') + 'a';
			}
			if (res[vp[i].first.second] == '.' && res[vp[i].first.first] != '.') {
				res[vp[i].first.second] =
					vp[i].second - (res[vp[i].first.first] - 'a') + 'a';
			}
		}
	}
	cout << "! " << res << "\n";
	cout << flush;
	return 0;
}