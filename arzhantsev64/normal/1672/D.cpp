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
    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i)
        cin >> v1[i];
    for (int i = 0; i < n; ++i)
        cin >> v2[i];
    vector<int> cnt(n + 10);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // cout << i << ' ' << j << endl;
        while (j < n && v2[i] != v1[j]) {
            cnt[v1[j]]++;
            j++;
        }
        if (j < n && v2[i] == v1[j]) {
            if (cnt[v2[i]] > 0)
                cnt[v2[i]]--;
            else
                j++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";    
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