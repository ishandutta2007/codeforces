#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt_zero = 0;
    int cnt_blocks = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0)
            cnt_zero++;
        if (a[i] != 0 && (i == 0 || a[i - 1] == 0))
            cnt_blocks++;
    }
    if (cnt_blocks == 0)
        cout << 0 << '\n';
    else if (cnt_blocks == 1)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}