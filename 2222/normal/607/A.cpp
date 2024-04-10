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
    vector<pii> a(n);
    for (auto &p : a) cin >> p.X >> p.Y;
    sort(all(a));
    vector<int> f(n + 1);
    REP (i, n) {
       int j = lower_bound(all(a), pii(a[i].X - a[i].Y, 0)) - a.begin();
       f[i + 1] = f[j] + 1;
    }
    cout << n - *max_element(all(f)) << endl;
    return 0;
}