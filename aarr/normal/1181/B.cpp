#include <iostream>
#include <algorithm>
using namespace std;

string s, ans, t, p;
string jam(string t, string p) {
	int x = 0;
	string q = "";
	for (int i = 0; i < t.size() || i < p.size(); i++) {
		if (i < p.size()) {
			x += p[i] - '0';
		}
		if (i < t.size()) {
			x += t[i] - '0';
		}
		q += (x % 10 + '0');
		x /= 10;
	}
	if (x > 0)
		q += (x + '0');
	return q;
}
string min(string t, string p) {
	if (t.size() < p.size()) {
		return t;
	}
	if (p.size() < t.size()) {
		return p;
	}
	for (int i = p.size(); i >= 0; i--) {
		if (t[i] < p[i])
			return t;
		if (p[i] < t[i])
			return p;
	}
	return t;
}
int main() {
	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		char c;
		cin >> c;
		s += c;
	}
	reverse(s.begin(), s.end());
	int x = l / 2 - 1, y = l - l / 2 - 1;
	while (x >= 0 && s[x] == '0') {
		x--;
	}
	if (x >= 0) {
		for (int i = 0; i <= x; i++) {
			t += s[i];
		}
		for (int i = x + 1; i < l; i++) {
			p += s[i];
		}
		//cout << t << " " << p << " ";
		ans = jam(t, p);
		//cout << ans << endl;
	}
	else {
		for (int i = 0; i < 200000; i++) {
			ans += "9";
		}
	}
	while (y < s.size() && s[y] == '0') {
		y++;
	}
	//cout << x << " " << y << endl;
	if (y < l - 1) {
		p.clear();
		t.clear();
		//cout << 73984934;
		for (int i = 0; i <= y; i++) {
			t += s[i];
		}
		for (int i = y + 1; i < l; i++) {
			p += s[i];
		}
		//cout << t << " " << p << " " << " " << jam(t, p) << " ";
		ans = min(ans, jam(t, p));
		//cout << ans << endl;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}