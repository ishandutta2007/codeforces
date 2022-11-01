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

int solve(string a, string b, int i) {
    a.insert(a.begin() + i, b[i]);
    for (; i <= n; ++i)
        if (a[i] != b[i]) {
            b.insert(b.begin() + i, a[i]);
            break;
        }
    return a == b;
}

int main() {
    string a, b;
    getline(cin, a);
    sscanf(a.data(), "%d", &n);
    getline(cin, a);
    getline(cin, b);
    // assert(n == sz(a));
    // assert(n == sz(b));
    // assert(a != b);
    // REP (p, 3) {
        // int x = (p & 1), y = (p & 2) >> 1;
        // lcs[p][0] = a[x] == b[y];
        // FOR (i, 1, n) {
            // lcs[p][i] = (a[i + x] == b[i + y] ? lcs[p][i - 1] + 1 : 0);
        // }
        // lcp[p][n - 1] = a[n - 1 - x] == b[n - 1 - y];
        // for (int i = n - 2; i >= 0; --i) {
            // lcp[p][i] = (a[i - x] == b[i - y] ? lcp[p][i + 1] + 1 : 0);
        // }
        // REP (i, n)
            // cout << lcs[p][i] << ' ';
        // cout << endl;
        // REP (i, n)
            // cout << lcp[p][i] << ' ';
        // cout << endl;
        // cout << endl;
    // }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            res += solve(a, b, i);
            res += solve(b, a, i);
            break;
        }
    }
    cout << res << endl;
    return 0;
}