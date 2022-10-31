#include <bits/stdc++.h>
using namespace std;
int main() {
	string s, t;
	cin >> s;
	cin >> t;
	int tcnt[26];
	int scnt[26];
	int rescnt[26];
	int q = 0;
	for (int i = 0; i < 26; i++) {
		tcnt[i] = 0;
		scnt[i] = 0;
		rescnt[i] = 0;
	}
	for (int i = 0; i < t.size(); i++) {
		tcnt[(int)(t[i] - 'a')]++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '?') {
			scnt[(int)(s[i] - 'a')]++;
		}
		else {
			q++;
		}
	}
	int j = 0;
	for (int i = 0; i < q; i++) {
		while (scnt[j] >= tcnt[j]) {
			scnt[j] -= tcnt[j];
			j = (j + 1) % 26;
		}
		rescnt[j]++;
		scnt[j]++;
	}
	j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			while (rescnt[j]==0) {
				j++;
			}
			s[i] = 'a' + j;
			rescnt[j]--;
		}
	}
	cout << s << endl;
	return 0;
}