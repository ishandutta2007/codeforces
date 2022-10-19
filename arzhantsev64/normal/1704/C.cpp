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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    v.push_back(v[0] + n);
    vector<int> lens;
    for (int i = 0; i < m; ++i)
        lens.push_back(v[i + 1] - v[i] - 1);
    sort(lens.rbegin(), lens.rend());
    int ans = 0;
    int moves = 0;
    for (int i = 0; i < m; ++i) {
        int len = lens[i] - 2 * moves;
        // cout << "> " << len << endl;
        if (len <= 0)
            continue;
        if (len <= 2) {
            moves += 1;
            ans += 1;
        } else {
            moves += 2;
            ans += len - 1;
        }
    }
    cout << n - ans << endl;
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