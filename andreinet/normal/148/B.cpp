#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const double eps = 1e-10;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    
    if (vd <= vp) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    double dp = t * vp;
    while (dp < c) {
        double time = dp / (vd - vp);
        double npos = dp + time * vp;
        if (npos < c) {
            ans++;
            double t1 = npos / vd;
            npos += t1 * vp;
            npos += f * vp;
            dp = npos;
        } else break;
    }
    cout << ans << '\n';
}