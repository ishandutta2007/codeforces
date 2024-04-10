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

int get(vc<string>& a, int k) {
    int n = a.size();
    int m = a[0].size();

    int ans = 0;
    rep(i, 0, n) {
        int lst = -1;
        rep(j, 0, m) {
            if (a[i][j] == '.') {
                if (j - lst >= k) {
                    ans++;
                }
            } else {
                lst = j;
            }
        }
    }
    return ans;
}

void solve(istream& cin, ostream& cout) {
    int n, m, k;
    cin >> n >> m >> k;
    vc<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int ans = get(a, k);
    if (k == 1) {
        cout << ans;
        return;
    }
    vc<string> b(m);
    rep(i, 0, m) {
        rep(j, 0, n) {
            b[i].push_back(a[j][i]);
        }
    }
    ans += get(b, k);
    cout << ans;
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