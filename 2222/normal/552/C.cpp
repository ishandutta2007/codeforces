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

bool solve(int w, int m) {
    if (w == 2)
        return true;
    vector<ll> a(1, 1);
    for (; a.back() * w <= m; )
        a.pb(a.back() * w);
    int k = sz(a);
    REP (p, 1 << k) {
        ll s = m;
        REP (i, k) if (p & 1 << i) s += a[i];
        bool ok = true;
        for (; s > 0; s /= w) {
            if ((s % w) > 1) {
                ok = false;
                break;
            }
        }
        if (s == 0 && ok) return true;
    }
    return false;
}

int main() {
    for (int w, m; cin >> w >> m; ) {
        puts(solve(w, m) ? "YES" : "NO");
    }
    return 0;
}