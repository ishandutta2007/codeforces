#include <bits/stdc++.h> 

using namespace std;

string a, b;
map <char, char> to;
set <pair <char, char>> s;

int main (int argc, char const *argv[]) {
	cin >> a >> b;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) continue;
		if (!to.count(a[i])) {
			to[a[i]] = b[i];
			to[b[i]] = a[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (to.count(b[i])) b[i] = to[b[i]];
	}
	if (a != b) {
		puts("-1");
		return 0;
	}
	for (auto it : to) {
		char a = it.first, b = it.second;
		if (a == b) continue;
		if (a > b) swap(a, b);
		s.insert(make_pair(a, b));
	}
	cout << s.size() << endl;
	for (auto it : s) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}