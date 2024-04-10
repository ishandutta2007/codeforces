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
    vector<pair<int, int>> aa;
    vector<pair<int, int>> bb;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int p = 1;
        while (x % (p * m) == 0) {
            p *= m;
        }
        if (!aa.empty() && aa.back().first == x / p) {
            int nn = aa.back().second;
            aa.pop_back();
            aa.push_back({x / p, p + nn});
        } else {
            aa.push_back({x / p, p});
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int p = 1;
        while (x % (p * m) == 0) {
            p *= m;
        }
        if (!bb.empty() && bb.back().first == x / p) {
            int nn = bb.back().second;
            bb.pop_back();
            bb.push_back({x / p, p + nn});
        } else {
            bb.push_back({x / p, p});
        }
    }

    if (aa == bb)
        cout << "Yes\n";
    else
        cout << "No\n";
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