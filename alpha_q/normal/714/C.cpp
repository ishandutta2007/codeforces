#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int t, cnt[N];
string cmd, s, p;

int toInt (string bin) {
	int ret = 0;
	for (int i = 0; i < bin.size(); ++i) {
		ret <<= 1;
		ret += bin[i] == '1';
	}
	return ret;
}

int main (int argc, char const *argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t; while (t--) {
		cin >> cmd >> s;

		if (cmd == "+") {
			p = "";
			for (int j = 0; j < s.size(); ++j) {
				if ((s[j] - '0') & 1) p += '1';
				else p += '0';
			}
			++cnt[toInt(p)];
		} else if (cmd == "-") {
			p = "";
			for (int j = 0; j < s.size(); ++j) {
				if ((s[j] - '0') & 1) p += '1';
				else p += '0';
			}
			--cnt[toInt(p)];
		} else {
			cout << cnt[toInt(s)] << '\n';
		}
	}
	return 0;
}