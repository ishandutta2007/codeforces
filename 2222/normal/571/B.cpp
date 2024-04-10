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

int F[5050][5050];
vector<int> a;
int d0;

int f(int i, int k0, int k1) {
    if (k0 == 0 && k1 == 0) {
        assert(i == sz(a) - 1);
        return 0;
    }
    int &res = F[k0][k1];
    if (res < 0) {
        res = 0;
        if (k0 > 0) res = max(res, a[i + d0] - a[i + d0 - 1] + f(i + d0, k0 - 1, k1));
        if (k1 > 0) res = max(res, a[i + d0 + 1] - a[i + d0] + f(i + d0 + 1, k0, k1 - 1));
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    a.resize(n);
    for (int &x : a) scanf("%d", &x);
    sort(all(a));
    ll res = a.back() - a.front();
    a.push_back(a.back() + 0);
    d0 = n / k;
    int k1 = n % k;
    int k0 = k - k1;
    CL(F, -1);
    assert(d0 * k + k1 == n);
    res -= f(0, k0, k1);
    cout << res << endl;
    return 0;
}