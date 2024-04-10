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

int main() {
    int n;
    cin >> n;
    vector<int> res;
    for (; n > 0; ) {
        int x = 0, m = n, d = 1;
        for (; m > 0; d *= 10) {
            int t = m % 10;
            m /= 10;
            x += t ? d : 0;
        }
        res.pb(x);
        n -= x;
    }
    cout << sz(res) << endl;
    for (int x : res)
        cout << x << ' ';
    cout << endl;
    return 0;
}