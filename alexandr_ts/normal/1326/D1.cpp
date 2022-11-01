#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const ll INF = 5e17 + 10;
const int M = 1e6 + 10;
const int N = 2e6 + 10;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

string solve2(string s) {
	string ans;
	int tl = 0, tr = (int)s.size() - 1;
	while (tl + 2 < tr) {
		if (s[tl] == s[tr]) {
			ans += s[tl];	
			tl++;
			tr--;
		} else {
			break;	
		}
	}
	s = {s.begin() + tl, s.begin() + tr + 1};	
	auto s2 = s;
	reverse(s2.begin(), s2.end());
	s2 = s + "#" + s2;
	auto z = z_function(s2);
	int maxlen = 0;
	for (int i = (int)z.size() - 1; i > z.size() / 2; --i) {
		if (i + z[i] == (int)z.size()) {
			maxlen = max(maxlen, z[i]);
		}
	}
	auto ret = ans;
	ret += s.substr(0, maxlen);
	reverse(ans.begin(), ans.end());
	ret += ans;
	return ret;
}

void solve() {
	string s;
	cin >> s;
	auto a1 = solve2(s);
	reverse(s.begin(), s.end());
	auto a2 = solve2(s);
	if (a1.size() > a2.size()) {
		cout << a1 << "\n";
	} else {
		cout << a2 << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}