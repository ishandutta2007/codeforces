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
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    vector<ll> a(n);
    for (ll& t : a) {
        int z;
        scanf("%d", &z);
        t = z;
    }
    vector<ll> l(n), r(n);
    FOR (i, 1, n) l[i] = a[i - 1] | l[i - 1];
    for (int i = n - 2; i >= 0; --i) r[i] = a[i + 1] | r[i + 1];
    ll res = 0;
    ll d = 1;
    for (; k > 0; --k) d *= x;
    REP (i, n) {
        res = max(res, l[i] | r[i] | (a[i] * d));
    }
    cout << res << endl;
    return 0;
}