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
    int n,m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < m - 1; ++i)
        if (b[m - 1 - i] != a[n - 1 - i]) {
            cout << "NO" << endl;
            return;
        }
    bool flag = false;
    for (int i = 0; i < n - m + 1; ++i)
        if (a[i] == b[0])
            flag = 1;
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
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

/*

7 4 8 1 6 10 3 5 2 9
*/