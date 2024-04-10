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
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int &x : p) {
        scanf("%d", &x);
        --x;
    }
    vector<pii> res;
    int x = -1, y = -1;
    REP (i, n) {
        if (p[p[i]] == i) {
            x = i;
            y = p[i];
            if (x == y) break;
        }
    }
    if (x < 0) {
        puts("NO");
        return 0;
    }
    if (x == y) {
        REP (i, n) {
            if (i != x) {
                res.pb({x, i});
            }
        }
    } else {
        if (x != y) {
            res.pb({x, y});
        }
        vector<bool> u(n);
        u[x] = u[y] = true;
        REP (i, n) {
            if (u[i]) continue;
            vector<int> c;
            for (int j = i; !u[j]; j = p[j]) {
                u[j] = true;
                c.pb(j);
            }
            if (sz(c) % 2) {
                puts("NO");
                return 0;
            }
            for (int j = 0; j < sz(c); j += 2) {
                res.pb({x, c[j]});
                res.pb({y, c[j + 1]});
            }
        }
    }
    assert(sz(res) + 1 == n);
    puts("YES");
    for (pii e : res) {
        printf("%d %d\n", e.X + 1, e.Y + 1);
    }
    return 0;
}