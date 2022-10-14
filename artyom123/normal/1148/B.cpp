#include <bits/stdc++.h>

using namespace std;

const long long INF = -1e18;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    long long ta, tb;
    cin >> n >> m >> ta >> tb;
    int k;
    cin >> k;
    if (k >= n || k >= m) {
        cout << -1;
        return 0;
    }
    vector <long long> a(n);
    vector <long long> b(m);
    for (auto &c : a) {
        cin >> c;
    }
    for (auto &c : b) {
        cin >> c;
    }
    long long ans = INF;
    for (int i = 0; i <= k; i++) {
        long long now = a[i] + ta;
        int ind = int(lower_bound(b.begin(), b.end(), now) - b.begin());
        if (ind + k - i >= m) {
            cout << -1;
            return 0;
        }
        ans = max(ans, b[ind + k - i] + tb);
    }
    cout << ans;
    return 0;
}