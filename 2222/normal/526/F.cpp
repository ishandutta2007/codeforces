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

typedef vector<int> vi;
typedef pair<int, int> pii;

int cnt[300000];
pii bmm[150000];

long solve(int *a, int *b, int n, int m) {
    bmm[0] = {b[0], b[0]};
    FOR (i, 1, m) {
        bmm[i].X = min(bmm[i - 1].X, b[i]);
        bmm[i].Y = max(bmm[i - 1].Y, b[i]);
    }
    long res = 0;
    int y0 = a[0], y1 = a[0];
    int j0 = 0, j1 = 0;
    REP (i, n) {
        y0 = min(y0, a[i]);
        y1 = max(y1, a[i]);
        int j = y1 - y0 - i - 1;
        if (0 <= j && j < m)
            res += (y0 < bmm[j].X && bmm[j].Y < y1);
        for (; j0 < m && bmm[j0].Y < y1; ++j0)
            if (bmm[j0].Y >= j0)
                --cnt[bmm[j0].Y - j0];
        for (; j1 < m && bmm[j1].X > y0; ++j1)
            if (bmm[j1].Y >= j1)
                ++cnt[bmm[j1].Y - j1];
        assert(j0 == 0 || bmm[j0 - 1].Y < y1);
        assert(j0 == m || y1 < bmm[j0].Y);
        assert(j1 == 0 || y0 < bmm[j1 - 1].X);
        assert(j1 == m || bmm[j1].X < y0);
        if (j0 < j1)
            res += cnt[y0 + i + 1];
    }
    for (; j0 < j1; ++j0)
        if (bmm[j0].Y >= j0)
            --cnt[bmm[j0].Y - j0];
    for (; j1 < j0; ++j1)
        if (bmm[j1].Y >= j1)
            ++cnt[bmm[j1].Y - j1];
    return res;
}

long doit(int *p, int n) {
    if (n == 1)
        return 1;
    int m = n / 2;
    int *q = p + m;
    n -= m;
    reverse(p, p + m);
    long res = doit(p, m) + doit(q, n) + solve(p, q, m, n) + solve(q, p, n, m);
    reverse(p, p + m);
    return res;
}

int n, p[300000];

int main() {
	scanf("%d", &n);
    REP (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x - 1] = y;
    }
    cout << doit(p, n) << std::endl;
	return 0;
}