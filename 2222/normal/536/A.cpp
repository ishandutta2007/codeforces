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

long A, B;

long cnt(int l, int r, int m) {
    long total = A * (r - l + 1) + B * ((long)(r + l) * (r - l + 1) / 2);
    return max(A + B * r, (total + m - 1) / m);
}

int main() {
    int n;
    cin >> A >> B >> n;
    A -= B;
    REP (i, n) {
        int l, t, m;
        cin >> l >> t >> m;
        int L = l, R = t + 100500;
        for (; L <= R; ) {
            int mid = (L + R) / 2;
            if (cnt(l, mid, m) <= t)
                L = mid + 1;
            else
                R = mid - 1;
        }
        cout << (R < l ? -1 : R) << endl;
    }
    return 0;
}