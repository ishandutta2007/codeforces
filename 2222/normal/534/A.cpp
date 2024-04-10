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
    for (int n; cin >> n; ) {
        if (n == 2) {
            puts("1");
            puts("1");
        } else if (n == 3) {
            puts("2");
            puts("1 3");
        } else {
            cout << n << endl;
            for (int x = 2; x <= n; x += 2)
                cout << x << ' ';
            for (int x = 1; x <= n; x += 2)
                cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}