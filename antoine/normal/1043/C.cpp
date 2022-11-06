#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

bool better(string s1, string s2) {
	s1 = min(s1, rev(s1));
	s2 = min(s2, rev(s2));
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	string s;
	cin >> s;

	string t(1, s[0]);
	string ans;
	for(int i = 1; i < (int)s.size(); ++i) {
		string opt0 = t + s[i];
		string opt1 = rev(t) + s[i];
		if(better(opt0, opt1)) {
			ans += '0';
			t = opt0;
		} else {
			ans += '1';
			t = opt1;
		}
	}
	if(t < rev(t))
		ans += '0';
	else {
		ans += '1';
		t = rev(t);
	}
cerr <<t << endl;

	for(auto &&x: ans)
		cout << x << ' ';
	return 0;
}