#include <bits/stdc++.h>
using namespace std;

const int BASE = 249;
const int MOD = 1000000009;

struct hash_str {
    vector <int> h;
    vector <int> p;
    hash_str (string s) {
	int n = s.size();
	h.resize(n);
	p.resize(n);
	h[0] = s[0];
	p[0] = 1;
	for (int i = 1; i < n; i++) {
	    h[i] = ((h[i - 1] * (long long) BASE) % MOD + s[i]) % MOD;
	    p[i] = ((p[i - 1] * (long long) BASE) % MOD);
	}
    }
    int get(int l, int r) {
	if (l == 0) return h[r];
	int res = (h[r] - (h[l - 1] * (long long) p[r - l + 1])) % MOD;
	if (res < 0)
	    res += MOD;
	return res;
    }
    int all() {
	return h[h.size() - 1];
    }
};

int main() {
    string s;
    cin >> s;
    hash_str p(s);
    string begin, end;
    cin >> begin >> end;
    hash_str pref(begin);
    hash_str suf(end);
    map <int, set <int> > substrs;
    for (int len = max(begin.length(), end.length()); len <= s.length(); len++) {
	for (int i = 0; i + len - 1 < s.length(); i++) {
	    int j = i + len - 1;
	    if(p.get(i, i + begin.length() - 1) == pref.all() && p.get(j - end.length() + 1, j) == suf.all())
		substrs[len].insert(p.get(i, j));
	}
    }
    int ans = 0;
    for (auto m : substrs) {
	ans += m.second.size();
    }
    cout << ans << endl;
}