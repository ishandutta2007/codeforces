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

int mod;
int n, m, b;
int a[555];
int f[555][555];

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }

int main() {
    cin >> n >> m >> b >> mod;
    f[m][b] = 1 % mod;
    REP (i, n) {
        int a;
        cin >> a;
        for (int i = m; i > 0; --i)
            for (int j = 0; j + a <= b; ++j)
                f[i - 1][j] = add(f[i - 1][j], f[i][j + a]);
    }
    int res = 0;
    for (int j = 0; j <= b; ++j)
        res = add(res, f[0][j]);
    cout << res << endl;
    return 0;
}