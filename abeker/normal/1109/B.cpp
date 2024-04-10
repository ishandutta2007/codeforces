#include <bits/stdc++.h>
using namespace std;

int N;
string s;

bool check(int pos) {
	string t = s.substr(pos, N - pos) + s.substr(0, pos);
	if (t == s)
		return false;
	string r = t;
	reverse(r.begin(), r.end());
	return r == t;
}

int main() {
	cin >> s;
	
	N = s.size();
	for (int i = 1; i < N; i++)
		if (check(i)) {
			puts("1");
			return 0;
		}
	
	for (int i = 0; i < N / 2; i++)
		if (s[i] != s[0]) {
			puts("2");
			return 0;
		}
	
	puts("Impossible");
	
	return 0;
}