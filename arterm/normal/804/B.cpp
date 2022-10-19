// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int mod = 1e9 + 7;

int mul(ll x, ll y) {
    return x * y % mod;
}

int udd(int &x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int add(int x, int y) {
    udd(x, y);
    return x;
}


void kill() {
    string s;
    cin >> s;
    int pw = 0;
    int cnt = 0;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b' && cnt == 0)
            continue;
        if (s[i] == 'a') {
            ++cnt;
            pw = add(1, mul(2, pw));
        } else {
            udd(ans, pw);
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    //
    kill();

    return 0;
}