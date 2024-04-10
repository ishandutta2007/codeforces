#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    n--;
    m--;
    
    vector<int> ndigs;
    while (ndigs.empty() || n > 0) {
        ndigs.push_back(n % 7);
        n /= 7;
    }
    vector<int> mdigs;
    while (mdigs.empty() || m > 0) {
        mdigs.push_back(m % 7);
        m /= 7;
    }
    int ans = 0;
    for (int conf = 0; conf < (1 << 7); ++conf) {
        if (__builtin_popcount(conf) != SZ(ndigs) + SZ(mdigs)) {
            continue;
        }
        vector<int> xdigs;
        for (int i = 0; i < 7; ++i) {
            if (conf & (1 << i)) {
                xdigs.push_back(i);
            }
        }
        do {
            bool ok = true;
            for (int i = SZ(ndigs) - 1; i >= 0; --i) {
                if (xdigs[i] > ndigs[i]) {
                    ok = false;
                    break;
                }
                if (xdigs[i] < ndigs[i]) {
                    break;
                }
            }
            for (int i = SZ(mdigs) - 1; i >= 0; --i) {
                if (xdigs[i + SZ(ndigs)] > mdigs[i]) {
                    ok = false;
                    break;
                }
                if (xdigs[i + SZ(ndigs)] < mdigs[i]) {
                    break;
                }
            }
            ans += ok;
        } while (next_permutation(xdigs.begin(), xdigs.end()));
    }

    cout << ans << '\n';
}