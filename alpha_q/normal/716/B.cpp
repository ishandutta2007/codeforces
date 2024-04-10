#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e14 + 10;

string s;
int cnt[1010], q = 0;
set <char> tot;
bool ok[30];

int main (int argc, char const *argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s; s = "#" + s;
	int n = s.size() - 1;

	if (n < 26) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i <= 26; ++i) {
		if (s[i] == '?') ++q;
		else ++cnt[s[i] - 'A'], tot.insert(s[i]);
	}

	int sz = tot.size();
	for (int i = 1, j = 26; j <= n; ++i, ++j) {
		if (sz + q == 26) {
			for (int k = i; k <= j; ++k) 
				if (s[k] != '?') ok[s[k] - 'A'] = 1;
			int now = 0;
			for (int k = i; k <= j; ++k) {
				if (s[k] == '?') {
					while (ok[now]) ++now;
					s[k] = ('A' + now);
					ok[now] = 1;
				}
			}
			for (int k = 1; k <= n; ++k)
				if (s[k] == '?') s[k] = 'A';
			cout << s.substr(1) << '\n';
			return 0;
		} else {
			if (s[i] == '?') --q;
			else {
				--cnt[s[i] - 'A'];
				if (cnt[s[i] - 'A'] == 0) --sz;
			}

			if (j != n) {
				if (s[j + 1] == '?') ++q;
				else {
					++cnt[s[j + 1] - 'A'];
					if (cnt[s[j + 1] - 'A'] == 1) ++sz;	
				}
			}
		}
	}

	cout << -1 << '\n';
	return 0;
}