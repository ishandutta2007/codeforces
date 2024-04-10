#include<bits/stdc++.h>

using namespace std;

string s, t;
int cnts[30], cntt[30], cnt;
stack<int> st;

bool check(int k) {
	long long dem = 0;
	for (int i = 0; i < 26; i++) {
		dem += max(0LL, 1LL * k * cntt[i] - cnts[i]);
	}
	if (dem <= cnt) return true;
	else return false;
}

void generate(int k) {
	for (int i = 0; i < 26; i++) {
		long long u = max(0LL, 1LL * k * cntt[i] - cnts[i]);
		while (u--) {
			st.push(i);
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (st.empty()) {
				s[i] = 'a';
				continue;
			}
			s[i] = (char) st.top() + 'a';
			st.pop();
		}
	}
	cout << s;
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> s >> t;
	for (auto u : s) {
		if (u == '?') {
			cnt++;
			continue;
		}
		cnts[u - 'a']++;
	}
	for (auto v : t) {
		cntt[v - 'a']++;
	}

	int l = 0, r = s.size();
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	for (int i = r; i >= l; i--) {
		if (check(i)) {
			generate(i);
		}
	}
	return 0;
}