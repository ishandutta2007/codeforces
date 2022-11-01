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

int n;
int c[555];
int F[555][555];

int f(int i, int j) {
    if (i == j)
        return 1;
    if (i + 1 == j)
        return 1 + (c[i] != c[j]);
    int &res = F[i][j];
    if (res < 0) {
        res = -1u/2;
        if (c[i] == c[j]) {
            res = f(i + 1, j - 1);
        }
        for (int k = i; k < j; ++k) {
            res = min(res, f(i, k) + f(k + 1, j));
        }
    }
    return res;
}

int main() {
    cin >> n;
    REP (i, n) cin >> c[i];
    CL(F, -1);
    cout << f(0, n - 1) << endl;
    return 0;
}