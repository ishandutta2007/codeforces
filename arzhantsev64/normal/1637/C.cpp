#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mid = 0;
    int can_move = 0;
    cin >> a[0];
    for (int i = 1; i < n - 1; ++i) {
        cin >> a[i];
        mid += a[i] + (a[i] % 2);
        if (a[i] >= 2)
            can_move = 1;
    }
    cin >> a[n - 1];
    if (n == 3 && a[1] % 2 == 1)
        cout << -1 << '\n';
    else if (!can_move)
        cout << -1 << '\n';
    else
        cout << mid / 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();


    return 0;
}