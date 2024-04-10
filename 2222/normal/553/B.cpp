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
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    FOR (i, 2, n + 1) {
        f[i] = min(f[i - 1] + f[i - 2], 1000000001000000001);
    }
    REP (i, n) a[i] = i;
    --k;
    REP (i, n - 1) {
        if (k >= f[n - i - 1]) {
            k -= f[n - i - 1];
            swap(a[i], a[i + 1]);
        }
    }
    assert(k == 0);
    REP (i, n) {
        if (i) putchar(' ');
        cout << a[i] + 1;
    }
    cout << endl;
    return 0;
}