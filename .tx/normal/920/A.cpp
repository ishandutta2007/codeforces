#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    int t;
    cin >> t;
    rep(it, 0, t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, 0, k) {
            int x;
            cin >> x;
            a[x - 1] = 1;
        }
        int ans = 0;
        while (true) {
            bool any = false;
            ans++;
            rep(i, 0, n) {
                if (a[i] == 0) {
                    any = true;
                    if (i && a[i - 1] == ans || (i + 1 < n) && a[i + 1] == ans) {
                        a[i] = ans + 1;
                    }
                }
            }
            if (!any) {
                break;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}