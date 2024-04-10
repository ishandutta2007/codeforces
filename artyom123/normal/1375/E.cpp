#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].se = i;
        cin >> a[i].fi;
    }
    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--) {
        vector<pair<pair<int, int>, int>> b;
        for (int j = 0; j < i; j++)
            if (a[j] > a[i]) b.pb(a[j], j);
        sort(all(b));
        for (auto &c : b) {
            swap(a[i], a[c.se]);
            ans.pb(c.se, i);
        }
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c.fi + 1 << " " << c.se + 1 << "\n";
    return 0;
}