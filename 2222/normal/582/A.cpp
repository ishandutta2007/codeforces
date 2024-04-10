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

int gcd(int x, int y) { for (; y; swap(x %= y, y)); return x; }

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> g(n * n);
    for (int &x : g) cin >> x;
    multiset<int> left(all(g));
    sort(g.rbegin(), g.rend());
    vector<int> res;
    for (int x : g) {
        if (left.count(x) == 0) continue;
        left.erase(left.find(x));
        for (int y : res) {
            int t = gcd(x, y);
            left.erase(left.find(t));
            left.erase(left.find(t));
        }
        res.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << endl;
    return 0;
}