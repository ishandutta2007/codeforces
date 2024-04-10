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
char a[22][22];
int cost[22][22];
pii moves[26][22];

int main() {
    gets(a[0]);
    sscanf(a[0], "%d%d", &n, &m);
    REP (i, n) gets(a[i]);
    vector<pii> moves;
    REP (i, n) {
        int s = -1u/2;
        REP (j, m) {
            scanf("%d", &cost[i][j]);
            s = min(s, cost[i][j]);
        }
        moves.pb({1 << i, s});
    }
    REP (j, m) {
        vector<pii> t(26);
        REP (i, n) {
            int c = a[i][j] - 'a';
            t[c].X |= 1 << i;
            t[c].Y = min(t[c].Y, -cost[i][j]);
        }
        REP (i, n) t[a[i][j] - 'a'].Y += cost[i][j];
        REP (i, 26)
            if (t[i].X)
                moves.pb(t[i]);
    }
    vector<int> f(1 << n, -1u/4);
    f[0] = 0;
    for (auto move : moves)
        for (int p = (1 << n); p --> 0; )
            f[p | move.X] = min(f[p | move.X], f[p] + move.Y);
    printf("%d\n", f.back());
    return 0;
}