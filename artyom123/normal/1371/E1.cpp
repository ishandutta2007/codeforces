#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(all(a));
    vector<int> ans;
    for (int x = 1; x <= 2000; x++) {
        bool f = true;
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && a[j] <= x + i) {
                cnt++;
                j++;
            }
            if (cnt - i == 0) {
                f = false;
                break;
            }
            if ((cnt - i) % p == 0) {
                f = false;
                break;
            }
        }
        if (f) ans.pb(x);
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c << " ";
    return 0;
}