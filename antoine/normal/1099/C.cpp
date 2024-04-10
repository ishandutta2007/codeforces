#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void imp() {
	cout << "Impossible";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	int k;
	cin >> s >> k;

	int len = 0;

	for (char c : s)
		if (c == '*' || c == '?')
			--len;
		else
			++len;

	if (k < len)
		imp();
	while (len < k) {
		const int i = s.find('?');
		if (i == -1)
			break;
		s.erase(s.begin() + i);
		++len;
	}

	if (len < k) {
		const int i = s.find('*');
		if (i == -1)
			imp();
		s = s.substr(0, i) + string(k - len - 1, s[i - 1]) + s.substr(i + 1);
		len = k;
	}

	for (char c : { '*', '?' }) {
		for (;;) {
			const int i = s.find(c);
			if (i == -1)
				break;
			s.erase(s.begin() + i);
			s.erase(s.begin() + i - 1);
		}
	}

	assert((int )s.size() == k);
	cout << s;
	return 0;
}