#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
typedef long double ld;
typedef long long ll;
typedef long long i64;

int rem(int x) {
    return abs(x) % 2;
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> x >> y;
        int col = rem(x) + 2 * rem(y);
        cout << col + 1 << "\n";
    }

}