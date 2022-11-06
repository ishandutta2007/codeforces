#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

typedef vector<pair<char, int>> vpci;

bool valid(vpci v) {
	for (size_t i = 1; i < v.size(); ++i) {
		char c = v[i].first, d = v[i - 1].first;
		if (c == d + 1 || d == c + 1)
			return false;
	}
	return true;
}

string toStr(vpci v) {
	string res;
	for (auto e : v)
		res += string(e.second, e.first);
	return res;
}

string f(vpci v) {
	if (v.size() <= 3) {
		sort(v.begin(), v.end());
		do {
			if (valid(v))
				return toStr(v);
		} while (next_permutation(v.begin(), v.end()));
		return "No answer";
	}
	string s = "3142";
	for (int i = 5; i <= (int) v.size(); ++i) {
		if (i & 1)
			s = s + char('0' + i);
		else
			s = char('0' + i) + s;
	}
	string res;
	for (char c : s) {
		auto e = v[c - '1'];
		res += string(e.second, e.first);
	}
	return res;
}

string f() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	map<char, int> occ;
	for (char c : s)
		++occ[c];

	vpci v(occ.begin(), occ.end());
	return f(v);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << f() << endl;
	return 0;
}