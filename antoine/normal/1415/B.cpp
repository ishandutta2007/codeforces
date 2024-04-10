#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {


    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x:a)
        cin >> x;

    int ans = n;
    for (int c = 1; c <= 100; ++c) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] != c) {
                res++;
                i += k - 1;
            }


        ans = min(ans, res);
    }
    return ans;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}