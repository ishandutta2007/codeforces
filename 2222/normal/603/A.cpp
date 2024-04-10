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

int f[2][3];

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> f(2, vector<int>(3));
    for (char c : s) {
        int x = c - '0';
        auto g = f;
        for (int k = 0; k < 3; ++k) {
            g[x][k] = max(g[x][k], f[x ^ 1][k] + 1);
            if (k) g[x][k] = max(g[x][k], f[x][k - 1] + 1);
        }
        swap(f, g);
    }
    int res = 0;
    REP (i, 2) REP (j, 3) res = max(res, f[i][j]);
    cout << res << endl;
    return 0;
}