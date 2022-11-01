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

int n;
char s[55][55];
char f[55][55];
char can[111][111];

int main() {
    n = atoi(gets(s[0]));
    REP (i, n) gets(s[i]);
    REP (i, 2 * n - 1)
        REP (j, 2 * n - 1)
            can[i][j] = 'x';
    can[n - 1][n - 1] = 'o';
    REP (i, n) REP (j, n)
        if (s[i][j] == 'o') {
            f[i][j] = 'o';
            REP (x, n) REP (y, n)
                if (s[x][y] == '.')
                    can[n - 1 + x - i][n - 1 + y - j] = '.';
        } else {
            f[i][j] = '.';
        }
    REP (i, n) REP (j, n)
        if (f[i][j] == 'o') {
            REP (x, n) REP (y, n)
                if (f[x][y] == '.' && can[n - 1 + x - i][n - 1 + y - j] == 'x')
                    f[x][y] = 'x';
        }
    REP (i, n) REP (j, n)
        if (s[i][j] != f[i][j]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    REP (i, 2 * n - 1)
        puts(can[i]);
    return 0;
}