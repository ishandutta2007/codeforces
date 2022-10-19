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
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int first = -1;
    int last = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == v[i + 1]) {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    if (first == -1) {
        cout << 0 << '\n';
    } else if (first == last) {
        cout << 0 << '\n';
    } else {
        cout << max((int)1, last - first - 1) << '\n';
    }
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