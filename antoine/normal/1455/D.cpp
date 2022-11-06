#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
    int n, x;
    cin >> n>> x;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;

    int i = 0, ans = 0;
    for(; !is_sorted(a.begin(), a.end()); ++ans) {
        while(i < n && a[i] <= x)
            ++i;
        if(i >= n) return -1;
        swap(a[i], x);
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