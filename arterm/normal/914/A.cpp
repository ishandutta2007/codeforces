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

const int inf = 1e9;

int main() {
#ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);

    int n;
    int ans = -inf;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bool sq = false;
        if (x >= 0) {
            int y = ceil(sqrt(x));
            for (int j = -2; j <= 2; ++j) {
                int z = y + j;
                if (z * z == x)
                    sq = true;
            }
        }
        if (!sq)
            ans = max(ans, x);
    }
    cout << ans << endl;

    return 0;
}