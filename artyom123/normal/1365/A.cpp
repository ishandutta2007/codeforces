#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &c : a) {
            for (auto &l : c) cin >> l;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < m; j++) s += a[i][j];
            if (s == 0) cnt1++;
        }
        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int i = 0; i < n; i++) s += a[i][j];
            if (s == 0) cnt2++;
        }
        int cnt = min(cnt1, cnt2);
        if (cnt % 2 == 0) cout << "Vivek\n";
        else cout << "Ashish\n";
    }
    return 0;
}