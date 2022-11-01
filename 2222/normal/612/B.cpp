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

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    REP (i, n) {
        int j;
        cin >> j;
        p[j - 1] = i;
    }
    ll res = 0;
    REP (i, n - 1) res += abs(p[i + 1] - p[i]);
    cout << res << endl;
    return 0;
}