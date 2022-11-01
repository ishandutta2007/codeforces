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
    vector<int> f(n + 1, n);
    REP (k, n) {
        int x;
        cin >> x;
        f[x] = f[x - 1] - 1;
    }
    cout << *min_element(all(f)) << endl;
    return 0;
}