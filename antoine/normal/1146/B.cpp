#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

string f(string s) {
	s.erase(remove(s.begin(), s.end(), 'a'), s.end());
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;

	int n = (int) s.size();
	int c = count(s.begin(), s.end(), 'a');

	int k = (n - c) / 2;
	if (c + 2 * k == n && f(s.substr(0, c + k)) == s.substr(c + k))
		cout << s.substr(0, c + k);
	else
		cout << ":(";
	return 0;
}