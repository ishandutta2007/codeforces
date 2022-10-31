#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int INF = (int)1 << 30;
    while (T--) {
        int N;
        cin >> N;
        map<int, int> mp;
        int res = 0;
        int a;
        int mn = INF;
        for (int i = 0; i < N; i++) {
            cin >> a;
            mp[a]++;
        }
        for (auto m : mp) {
            mn = min(mn, m.second);
        }
        vector<int> A(mn + 2, 0);
        for (auto m : mp) {
            a = m.second;
            //cerr << a << endl;
            A[1] += a;
            for (int i = 1; i <= mn; i++) {
                int d = (a + i) / (i + 1);
                if (d * (i + 1) - a <= d) {
                    A[i + 1] += d;
                } else {
                    A[i + 1] += INF;
                }
            }
        }
        res = INF;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > 0) {
                res = min(res, A[i]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}