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

int n, q;
struct query { int x, y; char dir; } b[200500];
vector<int> X, Y;

const int Z = 1 << 18;

int mx[Z * 2], my[Z * 2];

void add(int *mx, int x, int y) {
    for (x += Z; x; x /= 2)
        mx[x] = min(mx[x], y);
}

int sum(int *s, int i, int j) {
    int res = 0;
    for (i += Z, j += Z; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
        if (i & 1) res += s[i];
        if (~j & 1) res += s[j];
    }
    return res;
}

int findLastGe(int *mx, int x, int y) {
    int r = x + Z;
    for (; r > 1 && mx[r] > y; ) {
        if ((r & r - 1) == 0)
            return 0;
        r = (r - 1) / 2;
    }
    for (; r < Z; ) {
        r *= 2;
        if (mx[r + 1] <= y)
            ++r;
    }
    return r - Z;
}

int main() {
    scanf("%d%d", &n, &q);
    fill(mx, mx + Z * 2, n + 1);
    fill(my, my + Z * 2, n + 1);
    X.pb(0);
    Y.pb(0);
    REP (i, q) {
        scanf("%d%d %c", &b[i].x, &b[i].y, &b[i].dir);
        X.pb(b[i].x);
        Y.pb(b[i].y);
    }
    UN(X);
    UN(Y);
    REP (i, q) {
        int x = lower_bound(all(X), b[i].x) - X.begin();
        int y = lower_bound(all(Y), b[i].y) - Y.begin();
        int res = 0;
        if (b[i].dir == 'L') {
            if (my[y + Z] == n + 1) {
                int z = findLastGe(mx, x, y);
                res = X[x] - X[z];
                add(my, y, z);
            }
        } else {
            assert(b[i].dir == 'U');
            if (mx[x + Z] == n + 1) {
                int z = findLastGe(my, y, x);
                res = Y[y] - Y[z];
                add(mx, x, z);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}