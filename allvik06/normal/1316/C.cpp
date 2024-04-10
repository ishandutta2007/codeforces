#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = -1e16;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    int minnn = -1, minnm = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (minnn == -1 && x % p != 0) {
            minnn = i;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (minnm == -1 && x % p != 0) {
            minnm = i;
        }
    }
    cout << minnn + minnm;
}