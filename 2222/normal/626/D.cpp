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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));
    const int h = 5050;
    vector<int> s(h * 2);
    REP (j, n) REP (i, j) s[a[j] - a[i] + h]++;
    vector<ll> d(h * 4);
    REP (i, h * 2) REP (j, h * 2)
        d[i + j] += (ll)s[i] * s[j];
    ll num = 0;
    REP (i, h * 4) REP (j, h * 2)
        if ((i - h * 2) - (j - h) < 0)
            num += d[i] * s[j];
    ll denum = 1;
    REP (k, 3) denum *= n * (n - 1) / 2;
    printf("%.8lf\n", (double)num / denum);
    return 0;
}