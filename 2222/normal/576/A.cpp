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
    int n;
    cin >> n;
    vector<int> res;
    for (int p = 2; p <= n; ++p) {
        bool prime = true;
        for (int x = 2; x * x <= p; ++x)
            if (p % x == 0) {
                prime = false;
                break;
            }
        if (prime)
            for (int x = p; x <= n; x *= p)
                res.push_back(x);
    }
    cout << res.size() << endl;
    for (int x : res)
        cout << x << ' ';
    cout << endl;
    return 0;
}