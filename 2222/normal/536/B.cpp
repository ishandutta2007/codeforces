#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

const int mod = 1000000007;

int main() {
    int n, m;
    string p;
    cin >> n >> m >> p;
    vector<int> X(m);
    for (int &x : X) {
        cin >> x;
        --x;
    }
    sort(all(X));
    string s(n, '?');
    for (int i = 0, j = 0; i < n; ++i) {
        for (; j < m && i - X[j] >= sz(p); ++j);
        if (j < m && i - X[j] >= 0)
            s[i] = p[i - X[j]];
    }
    string t = p + '#' + s;
    vector<int> pi(sz(t));
    FOR (i, 1, sz(pi)) {
		int j = pi[i - 1];
        for (; j > 0 && t[i] != t[j]; j = pi[j - 1]);
		if (t[i] == t[j]) ++j;
		pi[i] = j;
	}
    int res = 1;
    for (int x : X) {
        if (pi[x + sz(p) * 2] != sz(p))
            res = 0;
    }
    for (char c : s)
        if (c == '?')
            res = (long)res * 26 % mod;
    cout << res << endl;
    return 0;
}