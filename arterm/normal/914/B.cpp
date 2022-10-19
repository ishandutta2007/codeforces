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

const int M = 100100;

int a[M];
int n;

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i < M; ++i)
        if (a[i] % 2 == 1) {
            cout << "Conan\n";
            return 0;
        }
    cout << "Agasa\n";
    return 0;
}