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

ll triangle(int s) {
    if (s < 0)
        return 0;
    return (s + 1) * ll(s + 2) / 2;
}

ll cut(int maxX, int maxY, int s) {
    if (s < 0) return 0;
    ll res = triangle(s);
    if (maxX < s)
        res -= triangle(s - maxX);
    if (maxY < s)
        res -= triangle(s - maxY);
    return res;
}

ll area(int maxX, int maxY, int minSum, int maxSum) {
    if (minSum > maxSum)
        return 0;
    ll res = ll(maxX + 1) * (maxY + 1);
    res -= cut(maxX, maxY, minSum - 1);
    res -= cut(maxX, maxY, maxX + maxY - maxSum - 1);
    return res;
}

ll solve(int a, int b, int c, int l, int d) {
    c = d - c;
    if (c < 0) return 0;
    l -= c;
    if (l < 0) return 0;
    int x1 = min(d - a - 1, l);
    int y1 = min(d - b - 1, l);
    if (x1 < 0 || y1 < 0) return 0;
    return area(x1, y1, max(0, d - a - b + 1), l);
}

ll solve2(int a, int b, int c, int l, int d) {
    b = d - b;
    c = d - c;
    if (b < 0 || c < 0) return 0;
    l -= b + c;
    if (l < 0) return 0;
    int x1 = min(d - a - 1, l);
    return max(x1 + 1, 0);
}

int main() {
    for (int a, b, c, l; cin >> a >> b >> c >> l; ) {
        ll res = 0;
        int md = max(a, max(b, c)) + l;
        for (int d = md; d >= 0; --d) {
            res += solve(a, b, c, l, d);
            res += solve(b, c, a, l, d);
            res += solve(c, a, b, l, d);
            res += solve2(a, b, c, l, d);
            res += solve2(b, c, a, l, d);
            res += solve2(c, a, b, l, d);
            if (a <= d && b <= d && c <= d && (3 * d - a - b - c) <= l)
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}