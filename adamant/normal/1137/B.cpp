#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

vector<int> pfunc(string s) {
	int n = s.size();
	vector<int> p(n);
	for(int i = 1; i < n; i++) {
		p[i] = p[i - 1];
		while(p[i] && s[i] != s[p[i]]) {
			p[i] = p[p[i] - 1];
		}
		if(s[i] == s[p[i]]) {
			p[i]++;
		}
	}
	return p;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int x = pfunc(t).back();
	int a = count(all(s), '0');
	int b = count(all(s), '1');
	int c = count(all(t), '0');
	int d = count(all(t), '1');
	string ans;
	if(c <= a && d <= b) {
		ans = t;
		a -= c, b -= d;
		string cyc = t.substr(x);
		c = count(all(cyc), '0');
		d = count(all(cyc), '1');
		while(c <= a && d <= b) {
			a -= c, b -= d;
			ans += cyc;
		}
		ans += string(a, '0');
		ans += string(b, '1');
	} else {
		ans = s;
	}
	cout << ans << endl;
	return 0;
}