#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> f(string s) {
	multiset<string> ms;
	const int n = (int) s.size();
	for (int i = 1; i < n; ++i) {
		ms.insert(s.substr(i));
		ms.insert(s.substr(0, i));
	}
	return vector<string>(ms.begin(), ms.end());
}

bool f(string s1, string s2) {
	s2.resize(s1.size());
	return s1 == s2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<string> v(2*n-2);
	for (string &s : v)
		cin >> s;

	const vector<string> vo = v;

	sort(v.begin(), v.end(), [](const string &s1, const string &s2) {
		return s1.size() > s2.size();
	});

	string s1 = string() + v[0] + v[1].back();
	string s2 = string() + v[1] + v[0].back();

	sort(v.begin(), v.end());
	vector<string> v1 = f(s1), v2 = f(s2);

	assert(v1 == v || v2 == v);
	const string str = v1 == v ? s1 : s2;

	cerr << "str : " << str << endl;

	set<int> S;

	for(string s :vo) {

		if(f(s, str) && !S.count((int)s.size())) {
			cout << 'P';
			S.insert((int)s.size());
		} else
			cout << 'S';
	}
	return 0;
}