#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s, t;
	cin >> s >> t;
	vector<string> S;
	vector<string> T;


	for (int i = 1; i <= s.length(); ++i)
		S.push_back(s.substr(0, i));
	for (int i = 1; i <= t.length(); ++i)
		T.push_back(t.substr(0, i));
	vector<string> P;
	for (string a : S)
		for (string b : T)
			P.push_back(a + b);

	std::sort(P.begin(), P.end(), [](const string &l, const string &r) {
		for (int i = 0; i < min(l.length(), r.length()); ++i) {
			if (l[i] < r[i])
				return true;
			if (l[i] > r[i])
				return false;
		}
		return l.length() < r.length();
	});

	cout << P[0];
	return 0;
}