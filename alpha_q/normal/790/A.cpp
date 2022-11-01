#include <bits/stdc++.h> 

using namespace std;

const int N = 110;

int k, n;
string s[N];
string t[N];
string choice[N];

int main (int argc, char const *argv[]) {
	for (int i = 1; i <= 26; ++i) {
		choice[i] = "A";
		choice[i][0] = 'A' + i - 1;
	}
	for (int i = 27; i <= 52; ++i) {
		choice[i] = choice[i - 26];
		choice[i] += "B";
		choice[i][1] = 'a' + i - 27;
	}
	cin >> n >> k;
	for (int i = 1; i <= n - k + 1; ++i) {
		cin >> s[i];
	}
	int pos = 0;
	int now = 1;
	while (now <= n - k + 1 and s[now][0] == 'N') {
		++now;
	}
	++pos;
	for (int i = 1; i <= now; ++i) {
		t[i] = choice[pos];
	}
	for (int i = now + 1; i < now + k; ++i) {
		t[i] = choice[++pos];
	}
	for (int i = now + 1, j = now + k; i <= n - k + 1; ++i, ++j) {
		if (s[i][0] == 'Y') {
			t[j] = choice[++pos];
		} else {
			t[j] = t[j - k + 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << t[i] << ' ';
	} cout << '\n';
  return 0;
}