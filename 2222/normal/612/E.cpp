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
    int n;
    cin >> n;
    vector<int> p(n);
    REP (i, n) {
        cin >> p[i];
        --p[i];
    }
    vector<bool> u(n);
    map<int, vector<int>> c;
    vector<int> q(n, -1);
    REP (i, n) {
        vector<int> w;
        for (int j = i; !u[j]; j = p[j]) {
            u[j] = true;
            w.pb(j);
        }
        if (sz(w) == 0) continue;
        if (sz(w) % 2) {
            REP (j, sz(w)) {
                q[w[j]] = w[(j + (sz(w) + 1) / 2) % sz(w)];
            }
        } else {
            auto g = c.find(sz(w));
            if (g == c.end()) {
                c[sz(w)] = w;
                continue;
            }
            auto &v = g->Y;
            REP (j, sz(w)) {
                q[w[j]] = v[j];
                q[v[j]] = w[(j + 1) % sz(w)];
            }
            c.erase(g);
        }
    }
    REP (i, n) {
        if (q[i] < 0 || p[i] != q[q[i]]) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP (i, n) {
        if (i) cout << ' ';
        cout << q[i] + 1;
    }
    cout << endl;
    return 0;
}