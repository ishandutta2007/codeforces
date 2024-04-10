#include <bits/stdc++.h>
using namespace std;

//#define int long long

#define endl '\n'

typedef long long ll;
typedef long double ldb;

const int MOD = 1e9 + 7;
const int p = 517 + rand() % 17957;

vector<int> h;
vector<int> ppow;

void prepHash(const string &s) {
	h.resize(s.size() + 1);
	ppow = h;
	ppow[0] = 1;
	for (int i = 0; i < (int) s.size(); i++) {
		ppow[i + 1] = 1LL * ppow[i] * p % MOD;
		h[i + 1] = (1LL * h[i] * p + s[i]) % MOD;
	}
}

int getHash(int pos, int len) {
	return ((h[pos + len] - 1LL * h[pos] * ppow[len]) % MOD + MOD) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "0" + s + "0";
	n += 2;
	vector<int> left(n), right(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			left[i] = i;
		else
			left[i] = left[i - 1];
	} 
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			right[i] = i;
		} else {
			right[i] = right[i + 1];
		}
	}
	string s2;
	int cur = 0;
	while (cur < n - 1) {
		s2.push_back('0' + (right[cur + 1] - cur) % 2);
		cur = right[cur + 1];
	}
	prepHash(s2);
	int q;
	cin >> q;
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			pref[i + 1] += 1;
		}
		pref[i + 1] += pref[i];
	}
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		int cntz1 = pref[l1 + len] - pref[l1];
		int cntz2 = pref[l2 + len] - pref[l2];
		if (cntz1 != cntz2) {
			cout << "No" << endl;
			continue;
		}
		if (cntz1 == 0) {
			cout << "Yes" << endl;
			continue;
		}
		int c1, c2;
		c1 = right[l1] - l1;
		c2 = right[l2] - l2;
		if ((c1 - c2) % 2 != 0) {
			cout << "No" << endl;
			continue;
		}
		int r1 = l1 + len - 1;
		int r2 = l2 + len - 1;
		c1 = r1 - left[r1];
		c2 = r2 - left[r2];
		if ((c1 - c2) % 2 != 0) {
			cout << "No" << endl;
			continue;
		}
		int pos1 = pref[right[l1]];
		int pos2 = pref[right[l2]];
		int len2 = cntz1 - 1;

		int h1 = getHash(pos1, len2);
		int h2 = getHash(pos2, len2);
		if (h1 == h2) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}