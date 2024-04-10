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

int n, m;
int r[5], c[20];
unsigned was[11][11][11][11][11][20];
vector<int> msks[6];
char ans[5][22];

bool solve(int i, int p) {
    if (i == m) {
        REP (j, n)
            if (r[j] != 0)
                return false;
        return true;
    }
    REP (i, 5)
        if (r[i] < 0)
            return false;
    unsigned &w = was[r[0]][r[1]][r[2]][r[3]][r[4]][i];
    if (w & (1u << p))
        return false;
    w |= 1u << p;
    for (int q : msks[c[i]]) {
        REP (j, 5) {
            if (q & 1 << j) {
                ans[j][i] = '*';
                if (~p & 1 << j)
                    --r[j];
            } else {
                ans[j][i] = '.';
            }                
        }
        if (solve(i + 1, q))
            return true;
        REP (j, 5) {
            if ((q & 1 << j) && (~p & 1 << j))
                ++r[j];
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    REP (i, n) cin >> r[i];
    REP (i, m) cin >> c[i];
    REP (p, 1 << n) {
        int blocks = 0;
        REP (i, 5) {
            if (((p >> i) & 3) == 1)
                ++blocks;
        }
        msks[blocks].pb(p);
    }
    bool ok = solve(0, 0);
    assert(ok);
    REP (i, n)
        puts(ans[i]);
    return 0;
}