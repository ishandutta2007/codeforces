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
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> f(1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    vector<int> d(1);
    for (int j = 0; j < m; ++j) {
        int was = f.size();
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(f.begin(), f.end(), a[i]);
            if (it == f.end())
                f.push_back(a[i]);
            else
                *it = a[i];
        }
        int u = f.size() - was;
        if (j >= 300 && d.back() == u) {
            res += (m - j) * u;
            break;
        }
        res += u;
        d.push_back(u);
    }
    cout << res << endl;
    return 0;
}