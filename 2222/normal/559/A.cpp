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

int a[6], x[7], y[7];

int main() {
    REP (i, 6) cin >> a[i];
    x[1] = a[0];
    y[1] = 0;
    x[2] = x[1];
    y[2] = y[1] + a[1];
    x[3] = x[2] - a[2];
    y[3] = y[2] + a[2];
    x[4] = x[3] - a[3];
    y[4] = y[3];
    x[5] = x[4];
    y[5] = y[4] - a[4];
    x[6] = x[5] + a[5];
    y[6] = y[5] - a[5];
    assert(x[6] == 0);
    assert(y[6] == 0);
    int area = 0;
    REP (i, 6) area += x[i + 1] * y[i] - x[i] * y[i + 1];
    area = abs(area);
    cout << area << endl;
    return 0;
}