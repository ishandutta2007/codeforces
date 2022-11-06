#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> LPS(const string s) {
	const int n = (int) s.size();
	vector<int> lps(n, 0);
	int len = 0;

	for (int i = 1; i < n;) {
		if (s[i] == s[len])
			lps[i++] = ++len;
		else if (len)
			len = lps[len - 1];
		else
			lps[i++] = 0;
	}
	return lps;
}

struct V {
	int o0, o1;
	bool operator<=(const V &other) const {
		return o0 <= other.o0 && o1 <= other.o1;
	}

	void operator+=(const V &other) {
		o0 += other.o0;
		o1 += other.o1;
	}

	V operator+(const V &other) const {
		return {o0 + other.o0, o1 + other.o1};
	}
};

V f(string s) {
	const int c0 = count(s.begin(), s.end(), '0');
	return {c0, (int)s.size() - c0};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s, t;
	cin >> s >> t;

	const V C = f(s);

	const V c1 = f(t);

	if (!(c1 <= C)) {
		cout << s;
		return 0;
	}

	const vector<int> lps = LPS(t);

	const string ts = !lps.back() ? t : t.substr(lps.back());
	const V c2 = f(ts);

	string res = t;
	V resc = c1;

	while ((c2.o0 || c2.o1) && resc + c2 <= C) {
		resc += c2;
		res += ts;
	}

	assert(C.o0 - resc.o0 >= 0);
	assert(C.o1 - resc.o1 >= 0);
	res += string(C.o0 - resc.o0, '0');
	res += string(C.o1 - resc.o1, '1');
	cout << res;
	return 0;
}