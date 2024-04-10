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

vector<int> freq(const string &s) {
    vector<int> r(26);
    for (char x : s) {
        assert('a' <= x && x <= 'z');
        r[x - 'a']++;
    }
    return r;
}

int main() {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    auto A = freq(a);
    auto B = freq(b);
    auto C = freq(c);
    int bx = 0, by = 0;
    for (int x = 0; x * sz(b) <= sz(a); ++x) {
        int y = sz(a) / sz(c);
        REP (i, 26) {
            if (C[i] == 0) continue;
            y = min(y, (A[i] - x * B[i]) / C[i]);
        }
        bool ok = true;
        REP (i, 26) {
            if (B[i] * x + C[i] * y > A[i]) {
                ok = false;
                break;
            }
        }
        if (ok && y >= 0 && x + y > bx + by) {
            bx = x;
            by = y;
        }
    }
    REP (i, bx) cout << b;
    REP (i, by) cout << c;
    REP (i, 26) {
        assert(A[i] - bx * B[i] - by * C[i] >= 0);
        for (int k = A[i] - bx * B[i] - by * C[i]; k > 0; --k) {
            putchar(i + 'a');
        }
    }
    puts("");
    return 0;
}