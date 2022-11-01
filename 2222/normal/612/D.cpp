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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pii> a(n);
    REP (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.pb({x, -1});
        a.pb({y, +1});
    }
    sort(all(a));
    int l = 0, c = 0;
    bool ok = false;
    vector<pii> res;
    for (auto &e : a) {
        if (c < k) {
            l = e.X;
            ok = false;
        }
        c -= e.Y;
        if (c >= k) {
            ok = true;
        } else if (ok) {
            res.emplace_back(l, e.X);
        }
    }
    printf("%d\n", sz(res));
    for (auto p : res) {
        printf("%d %d\n", p.X, p.Y);
    }
    return 0;
}