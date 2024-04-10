#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    int n, p, q;
    string s;
    cin >> n >> p >> q >> s;
    vector<bool> f(n + 1);
    f[n] = true;
    for (int i = n; i --> 0; ) {
        if (i + p <= n && !f[i])
            f[i] = f[i + p];
        if (i + q <= n && !f[i])
            f[i] = f[i + q];
    }
    if (!f[0]) {
        puts("-1");
        return 0;
    }
    vector<string> res;
    for (int i = 0; i < n; ) {
        if (i + p <= n && f[i + p]) {
            res.push_back(s.substr(i, p));
            i += p;
        } else {
            res.push_back(s.substr(i, q));
            i += q;
        }
    }
    cout << sz(res) << endl;
    for (auto &x : res)
        cout << x << endl;
    return 0;
}