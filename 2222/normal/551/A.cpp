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

int main() {
    int n;
    cin >> n;
    vector<pii> a(n);
    REP (i, n) {
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(all(a));
    reverse(all(a));
    for (int i = 0, j = 0; i < sz(a); ) {
        for (; j < sz(a) && a[i].X == a[j].X; ++j);
        int k = i + 1;
        for (; i < j; ++i) {
            a[i] = {a[i].Y, k};
        }
    }
    sort(all(a));
    REP (i, sz(a)) {
        if (i) putchar(' ');
        cout << a[i].Y;
    }
    cout << endl;
    return 0;
}